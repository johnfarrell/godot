/* modelmaker/modelmaker.h  */

#ifndef MODELMAKER_H
#define MODELMAKER_H

#include "types/sdf_core.h"
#include "mesh_maker.h"

#include "core/node_path.h"
#include "core/reference.h"
#include "scene/3d/spatial.h"
#include "scene/3d/mesh_instance.h"

class ModelMaker : public Reference {
	GDCLASS(ModelMaker, Reference);

protected:
	static void _bind_methods();

private:
	NodePath _parent_node;
	MeshMaker *_mesh_handler;
	SDFCore *_sdf_handler;

public:
	ModelMaker();
	~ModelMaker();

	ModelMaker(const NodePath par_node);

	void set_parent(const NodePath par_node);
	void create_model(const String file_path);
	void get_mesh();
};

#endif // MODELMAKER_H