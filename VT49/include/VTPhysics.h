#ifndef VTPHYSICS_H
#define VTPHYSICS_H

#include <btBulletDynamicsCommon.h>
#include <btCollisionObject.h>
#include <b3BulletFile.h>
#include <btBulletWorldImporter.h>
#include "SWSimulation.h"
#include <stdio.h>

using namespace bParse;
using namespace std;

class VTPhysics
{
	SWSimulation *SWS;
	btDefaultCollisionConfiguration *collisionConfiguration;
	btCollisionDispatcher *dispatcher;
	btBroadphaseInterface *overlappingPairCache;
	btSequentialImpulseConstraintSolver *solver;
	// btDiscreteDynamicsWorld *dynamicsWorld;
	btDynamicsWorld *dynamicsWorld;

public:
	VTPhysics(SWSimulation *SWS);
	~VTPhysics();
	bool Init();
	void Update();
};

#endif // VTPHYSICS_H
