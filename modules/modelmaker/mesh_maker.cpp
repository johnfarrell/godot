/* mesh_maker.cpp */

#include "mesh_maker.h"

MeshMaker::MeshMaker() {
    stl_handler = memnew(STL);
    obj_handler = memnew(OBJCore);
    collada_handler = memnew(ColladaCore);
    gltf_handler = memnew(GLTFCore);

}
MeshMaker::~MeshMaker() {
    memdelete(stl_handler);
    memdelete(obj_handler);
    memdelete(collada_handler);
    memdelete(gltf_handler);
}

void MeshMaker::_bind_methods() {
    ClassDB::bind_method(D_METHOD("create_mesh", "file_path"), &MeshMaker::create_mesh);
}

bool MeshMaker::create_mesh(String file_path) {
    return false;
}