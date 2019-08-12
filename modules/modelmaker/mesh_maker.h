/* mesh_maker.h */
#ifndef MESH_MAKER_H
#define MESH_MAKER_H

#include "types/stl_core.h"
#include "types/obj_core.h"
#include "types/collada_core.h"
#include "types/gltf_core.h"

#include "core/reference.h"
#include "scene/3d/mesh_instance.h"


class MeshMaker : public Reference {
	GDCLASS(MeshMaker, Reference);

protected:
	static void _bind_methods();

private:
    STL *_stl_handler;
    OBJCore *_obj_handler;
    ColladaCore *_collada_handler;
    GLTFCore *_gltf_handler;

public:
    MeshInstance mesh;

    MeshMaker();
    ~MeshMaker();

    Node* create_mesh(String file_path);
};

#endif // MESH_MAKER_H