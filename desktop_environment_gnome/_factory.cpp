#include "framework.h"
#include "node.h"


__FACTORY_EXPORT void aura_freebsd_factory(::factory::factory * pfactory);


__FACTORY_EXPORT void node_gnome_factory(::factory::factory * pfactory);


__FACTORY_EXPORT void desktop_environment_gnome_factory(::factory::factory * pfactory)
{

   aura_freebsd_factory(pfactory);

   node_gnome_factory(pfactory);

   pfactory->add_factory_item < ::desktop_environment_gnome::node, ::acme::node > ();


}



