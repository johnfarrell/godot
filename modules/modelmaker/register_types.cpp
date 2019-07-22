/* modelmaker/register_types.cpp */

#include "register_types.h"

#include "core/class_db.h"

#include "loaders/sdf_loader.h"
#include "mesh_maker.h"
#include "modelmaker.h"

// Register STL and its loader
static ResourceFormatLoaderSDF *sdf_loader = NULL;

// Register main model maker
void register_modelmaker_types() {
	ClassDB::register_class<ModelMaker>();
	ClassDB::register_class<MeshMaker>();

#ifdef TOOLS_ENABLED
	sdf_loader = memnew(ResourceFormatLoaderSDF);
	ResourceLoader::add_resource_format_loader(sdf_loader);
	// ClassDB::register_class<ResourceFormatLoaderSDF>();
#endif // TOOLS_ENABLED
}

void unregister_modelmaker_types() {
	memdelete(sdf_loader);
}