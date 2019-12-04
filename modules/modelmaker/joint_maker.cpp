#include "joint_maker.h"

JointMaker::JointMaker()
{

}

JointMaker::~JointMaker()
{

}

HingeJoint* JointMaker::create_hinge_joint(const NodePath nodeA, const NodePath nodeB)
{
	HingeJoint *joint = new HingeJoint();
	joint->set_node_a(nodeA);
	joint->set_node_b(nodeB);

	print_line("Here");
	return joint;
}

void JointMaker::_bind_methods() {
	ClassDB::bind_method(D_METHOD("create_hinge_joint", "nodeA", "nodeB"), &JointMaker::create_hinge_joint);
}
