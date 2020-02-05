/* modelmaker/modelmaker.cpp */

#include "modelmaker.h"
#include "utils.h"


ModelMaker::ModelMaker() {
	this->_mesh_handler = memnew(MeshMaker);
	this->_sdf_handler = memnew(SDFCore);
	// Nothing to do yet
}
ModelMaker::~ModelMaker() {
	memdelete(this->_mesh_handler);
	memdelete(this->_sdf_handler);
}

ModelMaker::ModelMaker(const NodePath par_node) {
	_parent_node = par_node;
}

void ModelMaker::set_parent(const NodePath par_node) {
	_parent_node = par_node;
}

String ModelMaker::create_model(const String file_name) {
	Node* mesh_status = _mesh_handler->create_mesh(file_name);

	return "ok";
}

void ModelMaker::get_mesh() {
	// return (*_mesh_handler).mesh;
}

void ModelMaker::_bind_methods() {
	// ClassDB::bind_method(D_METHOD("NAME", "ARGS"), &ModelMaker::Name);
	ClassDB::bind_method(D_METHOD("create_model", "file_path"), &ModelMaker::create_model);
	ClassDB::bind_method(D_METHOD("set_parent", "par_node"), &ModelMaker::set_parent);
}