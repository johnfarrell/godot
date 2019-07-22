#ifndef STL_CORE_H
#define STL_CORE_H

#include "scene/3d/mesh_instance.h"

class STLCore {

public:
    STLCore();
    ~STLCore();

    bool parse(String file_path);
};

#endif // STL_CORE_H