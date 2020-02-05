#ifndef COLLADA_CORE_H
#define COLLADA_CORE_H

#include "scene/3d/mesh_instance.h"

class ColladaCore {

public:
    ColladaCore();
    ~ColladaCore();

    Node* parse(String file_path);
};
#endif // COLLADA_CORE_H