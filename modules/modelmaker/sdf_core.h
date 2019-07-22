/* sdf_core.h */
#ifndef SDF_CORE_H
#define SDF_CORE_H

#include "core/reference.h"

class SDFCore : public Reference {
    GDCLASS(SDFCore, Reference);

protected:
    static void _bind_methods();

};

#endif // SDF_CORE_H