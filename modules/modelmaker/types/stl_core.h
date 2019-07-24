#ifndef STL_CORE_H
#define STL_CORE_H

#include "core/variant.h"

#include "scene/3d/mesh_instance.h"


class STL : public Resource {
	GDCLASS(STL, Resource);

protected:
	static void _bind_methods();

public:
	STL();
	~STL();

	bool load(String p_file);
};

#endif // STL_CORE_H