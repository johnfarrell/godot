/* sdf_loader.cpp */

#include "sdf_loader.h"


ResourceFormatLoaderSDF::ResourceFormatLoaderSDF() {
}
ResourceFormatLoaderSDF::~ResourceFormatLoaderSDF() {
}

RES ResourceFormatLoaderSDF::load(const String &p_path, const String &p_original_path, Error *r_error) {
	SDFCore *my = memnew(SDFCore);
	if (r_error)
		*r_error = OK;

	return Ref<SDFCore>(my);
}

void ResourceFormatLoaderSDF::get_recognized_extensions(List<String> *p_extensions) const {
	p_extensions->push_back("sdf");
	p_extensions->push_back("urdf");
}

String ResourceFormatLoaderSDF::get_resource_type(const String &p_path) const {
	if (p_path.get_extension().to_lower() == "sdf")
		return "SDF";
	return "";
}

bool ResourceFormatLoaderSDF::handles_type(const String &p_type) const {
	return (p_type == "SDF");
}