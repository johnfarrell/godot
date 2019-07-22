#ifndef SDF_H
#define SDF_H

#include "core/resource.h"
#include "core/variant.h"

class SDF : public Resource {
	GDCLASS(SDF, Resource);

protected:
	static void _bind_methods() {
		// TODO
	}

private:
	const String source_file;

public:
	SDF(){};
	~SDF(){};
};

#endif // STL_H