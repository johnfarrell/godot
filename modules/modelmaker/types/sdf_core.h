#ifndef SDF_CORE_H
#define SDF_CORE_H

#include "core/array.h"
#include "core/resource.h"
#include "core/variant.h"

#include <urdf_parser/urdf_parser.h>

#include <string>

class SDFCore : public Resource {
	GDCLASS(SDFCore, Resource);

protected:
	static void _bind_methods();

private:
	Array *_models;
	Array *_worlds;
	Array *_actors;
	Array *_lights;

	const String source_file;

public:
	bool load(std::string p_file);

	Array get_models();
	Array get_worlds();
	Array get_actors();
	Array get_lights();

	SDFCore();
	~SDFCore();
};

#endif // SDF_CORE_H