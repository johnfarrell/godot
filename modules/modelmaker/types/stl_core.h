#ifndef STL_CORE_H
#define STL_CORE_H

#include "scene/3d/mesh_instance.h"

class STL {

public:
	STL();
	~STL();

	bool load(String p_file);
};

#endif // STL_CORE_H