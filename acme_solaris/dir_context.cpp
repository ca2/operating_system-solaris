#include "framework.h"
#include "dir_context.h"
#include "acme/filesystem/filesystem/listing.h"


namespace acme_freebsd
{


   dir_context::dir_context()
   {


   }


   dir_context::~dir_context()
   {


   }


   void dir_context::initialize(::particle * pparticle)
   {

      ::acme_posix::dir_context::initialize(pparticle);

   }


   void dir_context::init_system()
   {

      ::acme_posix::dir_context::init_system();

   }


   void dir_context::init_context()
   {

      ::dir_context::init_context();

   }


   ::file::listing& dir_context::root_ones(::file::listing& listing)
   {

      ::file::path path;

      path = "/";

      listing.defer_add(path);

      return listing;

   }


} // namespace acme_freebsd



