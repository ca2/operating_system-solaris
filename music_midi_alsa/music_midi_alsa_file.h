#pragma once


#define C_TEMPO_MAP_CHK     16


namespace music
{


   namespace midi
   {


      namespace alsa
      {


      class CLASS_DECL_VERIWELL_MULTIMEDIA_MUSIC_MIDI_ALSA file :
         virtual public ::music::midi::file
      {
      public:



         file(::object * pobject);
         virtual ~file();


/*         double GetTempoShiftRate();

         bool IsTrackMute(int32_t iIndex);

         void MuteAll(bool bMute = true, int32_t iExcludeTrack = -1);

         void MuteTrack(int32_t iIndex, bool bMute = true);

         ::estatus WorkSeekBegin();

         ::estatus CalcTkLength();

         ::estatus CreateTempoMap();

         ::estatus ImmediatePutTempoChange();

         ::estatus GetTempoEvent(::music::midi::event & event);

         void OnStop();

         uint32_t GetImageSize();

         LPBYTE GetImage();

         ::estatus Format0();

         ::estatus InsertTempoEvent();

         ::music::midi::tempo_map_entry * GetTempoMapEntry(const imedia::position & position);

         int32_t GetTempoShift();

         ::estatus SetTempoShift(int32_t iTempoShift);

         void ToWorkStorage();

         void FromWorkStorage();

         int32_t GetKeyShift();

         int32_t SetKeyShift(int32_t iKeyShift);

         bool IsSoftKaraokeFile(bool bWork = false, string_array * pstra = NULL);

         bool IsXFFile();

         bool IsTune1000File();

         bool IsOpened();

         ::estatus RebuildIndex();

         ::estatus WriteHeader(MIDIFILEHDR * lpmfh);

         ::estatus ChangeEventDelta(::music::midi::event *pEvent, imedia::position tkNewDelta);

         ::estatus ReplaceSameDeltaEvent(::music::midi::event & pEventNew);

         ::estatus GetPreviousEvent(::music::midi::event * pPreviousEvent, ::music::midi::event * pEvent);

         ::estatus SaveFile(const char * lpFilePath);

         ::estatus WorkWriteXFTracks(string_array & tokena, imedia::position_array & positiona, ::music::xf::info_header & xfinfoheader);

         int32_t CalcMelodyTrack(::music::midi::events ** ppEvents, imedia::position_array * pTicks);

         int32_t WorkCalcMelodyTrack(::music::midi::events ** ppEvents, imedia::position_array & positiona, int_array & iaTokenLine);

         int32_t GetFormat();

         ::estatus WorkMergeTracks();

         ::estatus WorkStreamRender(LPMIDIHDR lpmh, imedia::position tkMax, uint32_t cbPrerollNomimalMax);

         ::estatus WorkGetNextEvent(::music::midi::event * & pevent, imedia::position tkMax, bool bTkMaxInclusive);

         ::estatus WorkGetNextRawEvent(::music::midi::event * & pevent, imedia::position tkMax, bool bTkMaxInclusive);

         ::estatus WorkGetNextRawMidiEvent(::music::midi::event * & pevent, imedia::position tkMax, bool bTkMaxInclusive);

         ::estatus WorkSeek(::imedia::position tkPosition, LPMIDIHDR lpmh);

         void delete_contents();

         int32_t GetDivision();

         imedia::position GetPosition();

         void AttachSeekSync(::ikaraoke::events_tracks_v1 * ptracksv1);

         bool IsNull();

         void WorkSeekEnd();

         ::estatus OpenFile(::music::midi::file::buffer &file, int32_t openMode);

         ::estatus OpenFile(::file::stream_buffer & file, int32_t openMode);

         ::estatus OpenFile(primitive::memory * pmemstorage, int32_t openMode, ::music::e_storage);

         ::estatus OpenFile(primitive::memory * pmemstorage, ::music::midi::file::e_open eopenmode, ::music::e_storage estorage);

         ::estatus SaveFile(::file::stream_buffer & file);

         ::estatus CloseFile();

         ::estatus GetFileInfo(PSMFFILEINFO psfi);

         int_ptr TicksToMillisecs(imedia::position tkOffset);

         void TicksToMillisecs(imedia::time_array *pMillisArray, imedia::position_array *pTickArray, int_ptr tkOffset);

         void TicksToMillisecs(imedia::time_2darray *p2DMillisArray, imedia::position_2darray * p2DTicksArray, int_ptr tkOffset);

         void PositionToTime(imedia::time_2darray  & timea, imedia::position_2darray  & positiona, int_ptr tkOffset);

         void PositionToTime(imedia::time_array  & timea, imedia::position_array  & positiona, int_ptr tkOffset);

         imedia::position MillisecsToTicks(imedia::time msOffset);

         imedia::time PositionToTime(imedia::position msOffset);

         imedia::position TimeToPosition(imedia::time msOffset);

         void MillisecsToTicks(imedia::position_array * pTickArray, imedia::time_array *pMillisArray, imedia::time msOffset);

         void TimeToPosition(imedia::position_array & positiona, imedia::time_array & timea, imedia::time msOffset);

         ::estatus StreamRender(LPMIDIHDR lpmh, imedia::position tkMax, uint32_t cbPrerollNomimalMax);

         ::estatus StreamEvent(imedia::position tkDelta, ::music::midi::event * Event, LPMIDIHDR lpmh, imedia::position tkMax, uint32_t cbPrerollNomimalMax);

         ::estatus StreamEventF1(imedia::position tkDelta, array < ::music::midi::event *, ::music::midi::event * > & eventptra, LPMIDIHDR lpmh, imedia::position tkMax, uint32_t cbPrerollNomimalMax);

         ::estatus seek(imedia::position tkPosition, LPMIDIHDR lpmh);

         ::estatus seek(imedia::position tkPosition);

         ::estatus Build();

         ::estatus GetNextEvent(::music::midi::event *& pevent, imedia::position tkMax, bool   bTkMaxInclusive);

         ::estatus GetNextEventTkPosition(imedia::position * pTkPosition, imedia::position tkMax);

         void _SyncSeek(imedia::position tkPosition, ::ikaraoke::events_tracks_v1 * ptracksv1);

         void _SyncSeek(imedia::position tkPosition);

         ::estatus InsertParmData(imedia::position tkDelta, LPMIDIHDR lpmh);

         ::estatus InsertLyricEvents(::ikaraoke::lyric_event_v1 * pLyricEvent, LPMIDIHDR lpmh);

         ::estatus InsertPadEvent(imedia::position tkDelta, LPMIDIHDR lpmh);

         void SetOpened(bool bOpened = true);
*/

      };


      } // namespace alsa


   } // namespace midi


} // namespace music





