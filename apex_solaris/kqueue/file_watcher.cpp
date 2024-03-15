//
// Created by camilo on Dec/11/21 08:08 AM BRT <3ThomasBorregaardSørensen!!
//



/**
	Copyright (c) 2009 James Wynn (james@jameswynn.com)

	Permission is hereby granted, free of charge, to any person obtaining a copy
	of this software and associated documentation files (the "Software"), to deal
	in the Software without restriction, including without limitation the rights
	to uxse, cxopy, mxodify, mxerge, pxublish, dxistribute, sxublicense, and/or sxell
	copies of the Software, and to permit persons to whom the Software is
	furnished to do so, subject to the following conditions:

	The above copyright notice and this permission notice shall be included in
	all copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
	THE SOFTWARE.

	James Wynn james@jameswynn.com
*/

#include "framework.h"

#include "file_watcher.h"

#include <sys/event.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>


namespace file_watcher
{

#define MAX_CHANGE_EVENT_SIZE 2000

	typedef struct kevent KEvent;

	struct EntryStruct
	{
		EntryStruct(const char* filename, time_t mtime = 0)
		: m_strFileName(filename), mModifiedTime(mtime)
		{
		}
		~EntryStruct()
		{
		}
      ::file::path m_strFileName;
		time_t mModifiedTime;
	};

	int comparator(const void* ke1, const void* ke2)
	{
		/*KEvent* kevent1 = (KEvent*) ke1;
		KEvent* kevent2 = (KEvent*) ke2;

		EntryStruct* event1 = (EntryStruct*)kevent1->udata;
		EntryStruct* event2 = (EntryStruct*)kevent2->udata;
		return strcmp(event1->m_strFileName, event2->m_strFileName);
		*/
		return strcmp(((EntryStruct*)(((KEvent*)(ke1))->udata))->m_strFileName, ((EntryStruct*)(((KEvent*)(ke2))->udata))->m_strFileName);
	}

   watch::watch()
   {
      m_stream = NULL;
      m_bRecursive = bRecursive;
      m_iChangeCount = 0;
      addAll();
   }

   watch::~watch()
   {
      removeAll();

   }


    bool watch::open(const ::file::path & pathFolder, bool bRecursive)
   {

      if(!::file::watch::open(pathFolder, bRecursive))
         {

         return false;

         }

      addAll();

      return true;

   }

		void file_watch::_addFile(const char * name, bool imitEvents = true)
		{
			//fprintf(stderr, "ADDED: %s\n", name.c_str());

			// create entry
			struct stat attrib;
			stat(name, &attrib);

			int fd = open(name, O_RDONLY);

			if(fd == -1)
				_throw(file_not_found_exception(name));

			++m_iChangeCount;

			char* namecopy = new char[strlen(name) + 1];
			strncpy(namecopy, name, strlen(name));
			namecopy[strlen(name)] = 0;
			EntryStruct* entry = new EntryStruct(namecopy, attrib.st_mtime);

			// set the event data at the end of the list
			EV_SET(&m_keventaChange[m_iChangeCount], fd, EVFILT_VNODE,
				   EV_ADD | EV_ENABLE | EV_ONESHOT,
				   NOTE_DELETE | NOTE_EXTEND | NOTE_WRITE | NOTE_ATTRIB,
				   0, (void*)entry);

			// qsort
			qsort(m_keventaChange + 1, m_iChangeCount, sizeof(KEvent), comparator);

			// handle action
			if(imitEvents)
				handle_action(name, action_add);
		}

		void file_watch::_removeFile(const char * name, bool imitEvents = true)
		{
			// bsearch
			KEvent target;
			EntryStruct tempEntry(name, 0);
			target.udata = &tempEntry;
			KEvent* ke = (KEvent*)bsearch(&target, &m_keventaChange, m_iChangeCount + 1, sizeof(KEvent), comparator);
			if(!ke)
				_throw(file_not_found_exception(name));

			tempEntry.m_strFileName = "";

			// delete
			close((int)ke->ident);
			delete((EntryStruct*)ke->udata);
			memset(ke, 0, sizeof(KEvent));

			// move end to current
			memcpy(ke, &m_keventaChange[m_iChangeCount], sizeof(KEvent));
			memset(&m_keventaChange[m_iChangeCount], 0, sizeof(KEvent));
			--m_iChangeCount;

			// qsort
			qsort(m_keventaChange + 1, m_iChangeCount, sizeof(KEvent), comparator);

			// handle action
			if(imitEvents)
				handle_action(name, action_delete);
		}

		// called when the directory is actually changed
		// means a file has been added or removed
		// rescans the watched directory adding/removing files and sending notices
		void file_watch::_rescan()
		{
			// if new file, call addFile
			// if missing file, call removeFile
			// if timestamp modified, call handle_action(filename, ACTION_MODIFIED);
			DIR* dir = opendir(m_strDirName);
			if(!dir)
				return;

			struct dirent* dentry;
			KEvent* ke = &m_keventaChange[1];
			EntryStruct* entry = 0;
			struct stat attrib;

			while((dentry = readdir(dir)) != NULL)
			{
				string fname = m_strDirName + "/" + dentry->d_name;
				stat(fname, &attrib);
				if(!S_ISREG(attrib.st_mode))
					continue;

				if(ke <= &m_keventaChange[m_iChangeCount])
				{
					entry = (EntryStruct*)ke->udata;
					int result = strcmp(entry->m_strFileName, fname);
					//fprintf(stderr, "[%s cmp %s]\n", entry->m_strFileName, fname.c_str());
					if(result == 0)
					{
						stat(entry->m_strFileName, &attrib);
						time_t timestamp = attrib.st_mtime;

						if(entry->mModifiedTime != timestamp)
						{
							entry->mModifiedTime = timestamp;
							handle_action(entry->m_strFileName, action_modify);
						}
						ke++;
					}
					else if(result < 0)
					{
						// f1 was deleted
						removeFile(entry->m_strFileName);
						ke++;
					}
					else
					{
						// f2 was created
						addFile(fname);
						ke++;
					}
				}
				else
				{
					// just add
					addFile(fname);
					ke++;
				}
			}//end while

			closedir(dir);

		}

   void watch::handle_action(const char * filename, e_action action)
   {
      m_plistener->handle_file_action(m_id, ::file::path(filename).folder(), ::file::path(filename).name(), action);
   }


//   void watch::myCallbackFunction(
//      ConstFSEventStreamRef streamRef,
//      void *clientCallBackInfo,
//      size_t numEvents,
//      void *eventPaths,
//      const FSEventStreamEventFlags eventFlags[],
//      const FSEventStreamEventId eventIds[])
//   {
//
//      int i;
//
//      char **paths = (char **) eventPaths;
//
//      watch * pstruct =(watch *)clientCallBackInfo;
//
//      // printf("Callback called\n");
//
//      ::file::path pathFolder1;
//
//      pathFolder1 = pstruct->m_strDirName;
//
//      for (i=0; i<numEvents; i++)
//      {
//
//         ::file::path path =paths[i];
//
//         if(!pstruct->m_bRecursive)
//         {
//
//            ::file::path pathFolder2;
//
//            pathFolder2 = path.folder();
//
//            if(pathFolder2.get_length() > pathFolder1.get_length())
//            {
//
//               continue;
//
//            }
//
//         }
//
//         if(eventFlags[i] & kFSEventStreamEventFlagItemRenamed)
//         {
//
//            pstruct->handle_action(path, action_modify);
//
//         }
//         if(eventFlags[i] & kFSEventStreamEventFlagItemModified)
//         {
//            pstruct->handle_action(path, action_modify);
//
//         }
//         if(eventFlags[i] & kFSEventStreamEventFlagItemCreated)
//         {
//            pstruct->handle_action(path, action_add);
//
//         }
//         //int count;
//         //eventIds[i], paths[i], eventFlags[i]);
//      }
//   }


   void file_watch::_addAll()
   {

       //add aura dir
			int fd = open(m_strDirName, O_RDONLY);
			EV_SET(&m_keventaChange[0], fd, EVFILT_VNODE,
				   EV_ADD | EV_ENABLE | EV_ONESHOT,
				   NOTE_DELETE | NOTE_EXTEND | NOTE_WRITE | NOTE_ATTRIB,
				   0, 0);

      fprintf(stderr, "ADDED: %s\n", m_strDirName.c_str());

       //scan directory and call addFile(name, false) on each file
			DIR* dir = opendir(m_strDirName);
			if(!dir)
				_throw(file_not_found_exception(m_strDirName));

			struct dirent* entry;
			struct stat attrib;
			while((entry = readdir(dir)) != NULL)
			{
				string fname = (m_strDirName + "/" + string(entry->d_name));
				stat(fname, &attrib);
				if(S_ISREG(attrib.st_mode))
					_addFile(fname, false);
				//else
				//	fprintf(stderr, "NOT ADDED: %s (%d)\n", fname.c_str(), attrib.st_mode);

			}//end while

			closedir(dir);

   }

   void watch::removeAll()
   {

//      FSEventStreamStop(m_stream);
//      ::multithreading::post_quit_and_wait(m_pthread, seconds (10));
//      FSEventStreamInvalidate(m_stream);
//      FSEventStreamRelease(m_stream);
//
//      m_stream = NULL;

			KEvent* ke = NULL;

			// go through list removing each file and sending an event
			for(int i = 0; i < m_iChangeCount; ++i)
			{
				ke = &m_keventaChange[i];
				//handle_action(name, Action::Delete);
				EntryStruct* entry = (EntryStruct*)ke->udata;

				handle_action(entry->m_strFileName, action_delete);

				// delete
				close((int)ke->ident);
				delete((EntryStruct*)ke->udata);
			}
   }



   bool os_file_watcher::step()
   {
      int nev = 0;
      struct kevent event;

      watch_map::pair * ppair = m_watchmap.PGetFirstAssoc();

      for(; ppair != NULL; ppair = m_watchmap.PGetNextAssoc(ppair))
      {
         watch_struct* watch = ppair->m_element2;

         if(watch == NULL)
         {

            continue;

         }

         while((nev = kevent(mDescriptor, (KEvent*)&(watch->m_keventaChange), (int) (watch->m_iChangeCount + 1), &event, 1, &mTimeOut)) != 0)
         {
            if(nev == -1)
            {
               perror("kevent");
            }
            else
            {
               EntryStruct* entry = 0;
               if((entry = (EntryStruct*)event.udata) != 0)
               {
                  //fprintf(stderr, "File: %s -- ", (char*)entry->m_strFileName);

                  if(event.fflags & NOTE_DELETE)
                  {
                     //fprintf(stderr, "File deleted\n");
                     //watch->handle_action(entry->m_strFileName, Action::Delete);
                     watch->removeFile(entry->m_strFileName);
                  }
                  if(event.fflags & NOTE_EXTEND ||
                     event.fflags & NOTE_WRITE ||
                     event.fflags & NOTE_ATTRIB)
                  {
                     //fprintf(stderr, "modified\n");
                     //watch->rescan();
                     struct stat attrib;
                     stat(entry->m_strFileName, &attrib);
                     entry->mModifiedTime = attrib.st_mtime;

                     watch->handle_action(entry->m_strFileName.name(), action_modify);
                  }
               }
               else
               {
                  //fprintf(stderr, "Dir: %s -- rescanning\n", watch->m_strDirName.c_str());
                  watch->rescan();
               }
            }
         }
      }]]

      // it is not needed, own OS monitors and dispatches events
      return false;


   }


   //--------
   file_watcher::file_watcher(::aura::application * papp) :
      ::object(papp)
   {
      mDescriptor = kqueue();
      mTimeOut.tv_sec = 0;
      mTimeOut.tv_nsec = 0;
   }

   //--------
   file_watcher::~file_watcher()
   {
//      watch_map::pair * ppair = m_watchmap.PGetFirstAssoc();
//      for(; ppair != NULL; ppair = m_watchmap.PGetNextAssoc(ppair))
//      {
//         delete ppair->m_element2;
//      }
      m_watchmap.remove_all();

      close(mDescriptor);
   }


   //--------
   id file_watcher::add_watch(const string & directory, listener * watcher, bool bRecursive, bool bOwn)
   {

      synch_lock sl(m_pmutex);

/*		int fd = open(directory.c_str(), O_RDONLY);
		if(fd == -1)
			perror("open");

		EV_SET(&change, fd, EVFILT_VNODE,
			   EV_ADD | EV_ENABLE | EV_ONESHOT,
			   NOTE_DELETE | NOTE_EXTEND | NOTE_WRITE | NOTE_ATTRIB,
			   0, (void*)"testing");
*/

      watch * pwatch = canew(watch(get_app(), ++mLastWatchID, directory, watcher, bRecursive));
      m_watchmap.set_at(mLastWatchID, pwatch);
      return mLastWatchID;
   }

   //--------
   void os_file_watcher::remove_watch(const string & directory)
   {
      watch_map::pair * ppair = m_watchmap.PGetFirstAssoc();
      for(; ppair != NULL; ppair = m_watchmap.PGetNextAssoc(ppair))
      {
         if(directory == ppair->m_element2->m_strDirName)
         {
            remove_watch(ppair->m_element1);
            return;
         }
      }
   }

   //--------
   void file_watcher::remove_watch(id watchid)
   {
      watch_map::pair * ppair = m_watchmap.PLookup((id &)watchid);

      if(ppair == NULL)
         return;

      watch* watch = ppair->m_element2;
      m_watchmap.remove_key(ppair->m_element1);

      //inotify_rm_watch(mFD, watchid);

      //delete watch;
      watch = 0;
   }


   string file_watcher::watch_path(id watchid)
   {

      return m_watchmap.PLookup(watchid)->m_element2->m_strDirName;

   }


   //--------
   void file_watcher::handle_action(action *)
   {

//      watch_struct * watch, const char * filename, uint32_t action
   }


} // namespace file_watcher



