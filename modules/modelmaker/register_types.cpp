/* modelmaker/register_types.cpp */

#include "register_types.h"

#include "core/class_db.h"

#include "loaders/sdf_loader.h"
#include "loaders/stl_loader.h"
#include "mesh_maker.h"
#include "modelmaker.h"
#include "joint_maker.h"

// Register STL and its loader
static ResourceFormatLoaderSDF *sdf_loader = NULL;
static ResourceFormatLoaderSTL *stl_loader = NULL;

// Register main model maker
void register_modelmaker_types() {
	ClassDB::register_class<ModelMaker>();
	ClassDB::register_class<MeshMaker>();
	ClassDB::register_class<JointMaker>();

#ifdef TOOLS_ENABLED
	sdf_loader = memnew(ResourceFormatLoaderSDF);
	ResourceLoader::add_resource_format_loader(sdf_loader);
	// ClassDB::register_class<ResourceFormatLoaderSDF>();

	stl_loader = memnew(ResourceFormatLoaderSTL);
	ResourceLoader::add_resource_format_loader(stl_loader);
#endif // TOOLS_ENABLED
}

void unregister_modelmaker_types() {
	memdelete(sdf_loader);
	memdelete(stl_loader);
}
