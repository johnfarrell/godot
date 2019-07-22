/* modelmaker/modelmaker.cpp */

#include "modelmaker.h"

ModelMaker::ModelMaker() {
	// Nothing to do yet
}
ModelMaker::~ModelMaker() {}

ModelMaker::ModelMaker(const NodePath par_node) {
	parent_node = par_node;
}

void ModelMaker::set_parent(const NodePath par_node) {
	parent_node = par_node;
}

void ModelMaker::create_model(const String file_path) {
}

void ModelMaker::_bind_methods() {
	// ClassDB::bind_method(D_METHOD("NAME", "ARGS"), &ModelMaker::Name);
	ClassDB::bind_method(D_METHOD("create_model", "file_path"), &ModelMaker::create_model);
	ClassDB::bind_method(D_METHOD("set_parent", "par_node"), &ModelMaker::set_parent);
}