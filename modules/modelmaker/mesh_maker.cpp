/* mesh_maker.cpp */

#include "mesh_maker.h"

MeshMaker::MeshMaker() {
	_stl_handler = memnew(STL);
	_obj_handler = memnew(OBJCore);
	_collada_handler = memnew(ColladaCore);
	_gltf_handler = memnew(GLTFCore);
}
MeshMaker::~MeshMaker() {
	memdelete(_stl_handler);
	memdelete(_obj_handler);
	memdelete(_collada_handler);
	memdelete(_gltf_handler);
}

String MeshMaker::create_mesh(String file_path) {
	return _collada_handler->parse(file_path);
}

void MeshMaker::_bind_methods() {
	ClassDB::bind_method(D_METHOD("create_mesh", "file_path"), &MeshMaker::create_mesh);
}