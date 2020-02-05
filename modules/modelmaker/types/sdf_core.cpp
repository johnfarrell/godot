#include "sdf_core.h"

// This is a hacky suggested fix to solve the issue down below. Doesn't seem to work
// #define GLIBCXX_USE_CXX11_ABI 0
// #include <urdf_parser/urdf_parser.h>
// #include <stdlib.h>
#include <string>

SDFCore::SDFCore() {
	_models = memnew(Array);
	_worlds = memnew(Array);
	_actors = memnew(Array);
	_lights = memnew(Array);
}

SDFCore::~SDFCore() {
	memdelete(_models);
	memdelete(_worlds);
	memdelete(_actors);
	memdelete(_lights);
}

Array SDFCore::get_models() {
	return *this->_models;
}
Array SDFCore::get_worlds() {
	return *this->_worlds;
}
Array SDFCore::get_actors() {
	return *this->_actors;
}
Array SDFCore::get_lights() {
	return *this->_lights;
}

bool SDFCore::load(std::string p_file) {
	// ERROR ON THIS LINE: 56
	// undefined reference to 'sdf::readFile(std::__cxx11::basic_string<char, std::char_traits<char>, ....)
	//                                       ^^^^^^^^^^^^^^^^^^^^^^^^^^
	//                                        important part
	//
	// The actual definition of the function is sdf::readFile(std::string) (Found in sdformat/include/parser.hh:57) 
	// and the linker is looking for incorrect version.
	// I believe this is due to the different ABIs used by the SDFormat lib and Godot.  I reached out to the developers
	// and Godot uses C++03, while SDFormat uses either C++11 or C++14, its hard to determine looking through the
	// Makefiles.
	// They introduced different implementations of std:string in GCC 5.x to conform to C++11 standards, and I believe
	// this is where the issue is.
	// The developers of Godot are currently in the process of porting the codebase to C++11, but it looks like it wont
	// be officially supported until 3.2 is released according to
	// https://github.com/godotengine/godot/commit/5dae2ea777da5395cf1b1e9a8bc6abc93f6ae6bb
	// I have merged those changes into my build to try to get it to work but it doesnt seem to want to work.
	//
	// #define GLIBCXX_USE_CXX11_ABI 0
	//
	// I tried the fix suggested at https://gcc.gnu.org/onlinedocs/gcc-5.2.0/libstdc++/manual/manual/using_dual_abi.html
	// but it seems thats mainly for code that uses C++11 linking to older code, not older code linking to C++11.
	//
	// I've tried rebuilding both SDFormat and Godot various times with different std versions, but haven't figured it out yet.
	return false;
}

void SDFCore::_bind_methods() {
	// ClassDB::bind_method(D_METHOD("load", "p_file"), &SDFCore::load);

	ClassDB::bind_method(D_METHOD("get_models"), &SDFCore::get_models);
	ClassDB::bind_method(D_METHOD("get_worlds"), &SDFCore::get_worlds);
	ClassDB::bind_method(D_METHOD("get_actors"), &SDFCore::get_actors);
	ClassDB::bind_method(D_METHOD("get_lights"), &SDFCore::get_lights);
}