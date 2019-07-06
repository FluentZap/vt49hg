#include "VTPhysics.h"

VTPhysics::VTPhysics(SWSimulation *SWS)
{
    VTPhysics::SWS = SWS;
}

VTPhysics::~VTPhysics()
{
}

bool VTPhysics::Init() 
{
    //Collision configuration contains default setup for memory, collision setup.
    collisionConfiguration = new btDefaultCollisionConfiguration();
    //Collision Processing
    dispatcher = new btCollisionDispatcher(collisionConfiguration);
    overlappingPairCache = new btDbvtBroadphase();
    solver = new btSequentialImpulseConstraintSolver;    
    dynamicsWorld = new btDiscreteDynamicsWorld(dispatcher, overlappingPairCache, solver, collisionConfiguration);
    dynamicsWorld->setGravity(btVector3(0.01f, 0, 0));
    //Done with basic world setup
    
    
    btAlignedObjectArray<btCollisionShape *> collisionShapes;
    btCollisionShape *VT49Mesh;
    btCollisionShape *VT49Mesh2;
    btBulletWorldImporter import(0); //don't store info into the world
    if (import.loadFile("Box.bullet"))
    {
        int numShape = import.getNumCollisionShapes();
        if (numShape)
        {
            VT49Mesh = (btConvexHullShape *)import.getCollisionShapeByIndex(0);
            //VT49Mesh2 = (btConvexHullShape*)import.getCollisionShapeByIndex(0);
        }
    }
    collisionShapes.push_back(VT49Mesh);
    //collisionShapes.push_back(VT49Mesh2);

    {
        btCollisionShape *groundShape = new btBoxShape(btVector3(btScalar(1.), btScalar(1.), btScalar(1.)));

        collisionShapes.push_back(groundShape);

        btTransform groundTransform;
        groundTransform.setIdentity();
        groundTransform.setOrigin(btVector3(0, 0, 30));

        btScalar mass(0.);

        //rigidbody is dynamic if and only if mass is non zero, otherwise static
        bool isDynamic = (mass != 0.f);

        btVector3 localInertia(0, 0, 0);
        if (isDynamic)
            groundShape->calculateLocalInertia(mass, localInertia);

        //using motionstate is optional, it provides interpolation capabilities, and only synchronizes 'active' objects
        btDefaultMotionState *myMotionState = new btDefaultMotionState(groundTransform);
        //btRigidBody::btRigidBodyConstructionInfo rbInfo(mass, myMotionState, groundShape, localInertia);
        btRigidBody::btRigidBodyConstructionInfo rbInfo(mass, myMotionState, VT49Mesh, localInertia);

        btRigidBody *body = new btRigidBody(rbInfo);

        //add the body to the dynamics world
        dynamicsWorld->addRigidBody(body);
    }

    {
        //create a dynamic rigidbody

        btCollisionShape *colShape = new btBoxShape(btVector3(5, 5, 5));
        //btCollisionShape* colShape = new btSphereShape(btScalar(5.));
        collisionShapes.push_back(colShape);

        /// Create Dynamic Objects
        btTransform startTransform;
        startTransform.setIdentity();

        btScalar mass(1.f);

        //rigidbody is dynamic if and only if mass is non zero, otherwise static
        bool isDynamic = (mass != 0.f);

        btVector3 localInertia(0, 0, 0);
        if (isDynamic)
            colShape->calculateLocalInertia(mass, localInertia);

        startTransform.setOrigin(btVector3(0, 0, 0));

        //using motionstate is recommended, it provides interpolation capabilities, and only synchronizes 'active' objects
        btDefaultMotionState *myMotionState = new btDefaultMotionState(startTransform);
        btRigidBody::btRigidBodyConstructionInfo rbInfo(mass, myMotionState, VT49Mesh, localInertia);
        btRigidBody *body = new btRigidBody(rbInfo);

        dynamicsWorld->addRigidBody(body);

        //btHingeConstraint* hinge = new btHingeConstraint(*body, btVector3(1, 0, 0), btVector3(1, 0, 0), true);
        //hinge->setAngularOnly(true);
        //dynamicsWorld->addConstraint(hinge);
    }

    //b3BulletFile* fileloader = new b3BulletFile("VT49.bullet");
    //fileloader->parseData();
    //fileloader.m_rigidBodies[0];
    //fileloader.m_collisionObjects[]
    //btcol

    //btBulletWorldImporter* fileloader = new btBulletWorldImporter(dynamicsWorld);
    //fileloader->loadFile("VT49.bullet");

    //print positions of all objects

    btCollisionObject *obj = dynamicsWorld->getCollisionObjectArray()[1];
    btRigidBody *body = btRigidBody::upcast(obj);
    btTransform trans;

    if (body && body->getMotionState())
    {
        body->getMotionState()->getWorldTransform(trans);
    }
    else
    {
        trans = obj->getWorldTransform();
    }

    printf("world pos object %d = %f,%f,%f\n", float(trans.getOrigin().getX()), float(trans.getOrigin().getY()), float(trans.getOrigin().getZ()));
}

void VTPhysics::Update()
{
    dynamicsWorld->stepSimulation(1.f / 60.f, 10);

    btCollisionObject *obj = dynamicsWorld->getCollisionObjectArray()[1];
    btRigidBody *body = btRigidBody::upcast(obj);

    btTransform trans;

    if (body && body->getMotionState())
    {
        body->getMotionState()->getWorldTransform(trans);
    }
    else
    {
        trans = obj->getWorldTransform();
    }
    // printf("world pos object %d = %f,%f,%f\n", float(trans.getOrigin().getX()), float(trans.getOrigin().getY()), float(trans.getOrigin().getZ()));
    
    // body->setActivationState(DISABLE_DEACTIVATION);
    // body->activate(true);
    // body->getMotionState()->getWorldTransform(trans);
}