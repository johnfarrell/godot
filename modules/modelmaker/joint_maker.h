#ifndef JOINT_MAKER_H
#define JOINT_MAKER_H

#include "core/reference.h"
#include "scene/3d/physics_joint.h"

class JointMaker : public Reference
{
	GDCLASS(JointMaker, Reference)


protected:
	static void _bind_methods();

public:
	JointMaker();
	~JointMaker();

	HingeJoint* create_hinge_joint(const NodePath nodeA, const NodePath nodeB);
	Generic6DOFJoint create_gen6DOF_joint();
};

#endif // JOINT_MAKER_H
