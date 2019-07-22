#ifndef SDF_H
#define SDF_H

#include "core/array.h"
#include "core/resource.h"
#include "core/variant.h"

class SDF : public Resource {
	GDCLASS(SDF, Resource);

protected:
	static void _bind_methods();

private:
	Array *_models;
	Array *_worlds;
	Array *_actors;
	Array *_lights;

	const String source_file;

public:
	bool load(String p_file);

	Array get_models();
	Array get_worlds();
	Array get_actors();
	Array get_lights();

	SDF();
	~SDF();
};

#endif // STL_H