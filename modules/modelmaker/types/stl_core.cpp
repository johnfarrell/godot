/* stl_core.cpp */

#include "stl_core.h"

STL::STL() {
}

STL::~STL() {
}

bool STL::load(String p_file) {
	return false;
}

void STL::_bind_methods() {
	ClassDB::bind_method(D_METHOD("load", "p_file"), &STL::load);
}