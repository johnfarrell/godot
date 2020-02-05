#ifndef OBJ_CORE_H
#define OBJ_CORE_H

#include "scene/3d/mesh_instance.h"

class OBJCore {

public:
    OBJCore();
    ~OBJCore();
    
    bool parse(String file_path);
};

#endif // OBJ_CORE_H