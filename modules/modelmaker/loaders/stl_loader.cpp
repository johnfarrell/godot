/* stl_loader.cpp */

#include "stl_loader.h"


ResourceFormatLoaderSTL::ResourceFormatLoaderSTL() {
}
ResourceFormatLoaderSTL::~ResourceFormatLoaderSTL() {
}

RES ResourceFormatLoaderSTL::load(const String &p_path, const String &p_original_path, Error *r_error) {
	STL *my = memnew(STL);
	if (r_error)
		*r_error = OK;

	return Ref<STL>(my);
}

void ResourceFormatLoaderSTL::get_recognized_extensions(List<String> *p_extensions) const {
	p_extensions->push_back("stl");
}

String ResourceFormatLoaderSTL::get_resource_type(const String &p_path) const {
	if (p_path.get_extension().to_lower() == "stl")
		return "STL";
	return "";
}

bool ResourceFormatLoaderSTL::handles_type(const String &p_type) const {
	return (p_type == "STL");
}