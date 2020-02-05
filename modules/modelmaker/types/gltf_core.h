#ifndef GLTF_CORE_H
#define GLTF_CORE_H

#include "scene/3d/mesh_instance.h"

class GLTFCore {

public:
    GLTFCore();
    ~GLTFCore();
    
    bool parse(String file_path);
};

#endif // GLTF_CORE_H