/* stl_loader.h */
#ifndef SDF_LOADER_H
#define SDF_LOADER_H

#include "core/io/resource_loader.h"

#include "../types/sdf_core.h"

class ResourceFormatLoaderSDF : public ResourceFormatLoader {
private:
public:
	virtual RES load(const String &p_path, const String &p_original_path, Error *r_error = NULL);
	virtual void get_recognized_extensions(List<String> *p_extensions) const;
	virtual bool handles_type(const String &p_type) const;
	virtual String get_resource_type(const String &p_path) const;

	ResourceFormatLoaderSDF();
	virtual ~ResourceFormatLoaderSDF();
};

#endif // SDF_LOADER_H