#pragma once

#include "utXMLParser.h"
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
using namespace std;


struct DaePhysicsRigidBody
{

	enum PhysicsShapes {Box, Sphere, Mesh}; 

	string			id;
	string			name;
	float			mass;
	string			material;
	PhysicsShapes	shape;
	Vec3f			extents;
	float			radius;
	string			geometry;

	friend std::ofstream& operator << (std::ofstream& s, DaePhysicsRigidBody* item)
	{
		if (item)
		{
			s << "<Attachment type=\"physics\" mass=\"" << item->mass << "\" shape=\"";
			switch (item->shape)
			{
			case Box:
				s << "box\" x=\"" << item->extents.x << "\" y=\"" << item->extents.y << "\" z=\"" << item->extents.z << "\" />";
				break;
			case Sphere:
				s << "sphere\" radius=\"" << item->radius << "\" />";
				break;
			case Mesh:
				s << "mesh\" />";
				break;
			};
		}
		return s;
	}

	bool parse( const XMLNode &physicNode )
	{
		id = physicNode.getAttribute( "sid", "" );
		if (id == "") return false;
		name = physicNode.getAttribute( "name", "" );

		XMLNode technique = physicNode.getChildNode( "technique_common" );
		if( !technique.getChildNode( "mass" ).isEmpty())
			if( !technique.getChildNode( "mass" ).isEmpty() &&
				technique.getChildNode( "mass" ).getText() != 0x0 )
					mass = (float) atof(technique.getChildNode( "mass" ).getText());
			else
				return false;
		else if (technique.getChildNode( "dynamic" ).getText() != 0x0 )
			mass = _stricmp(technique.getChildNode( "dynamic" ).getText(), "true")==0 ? 0.0f : 1.0f;
		else
			return false;
		if( !technique.getChildNode( "instance_physics_material" ).isEmpty() )
			material = technique.getAttribute( "url", "" );
		
		XMLNode shapeNode = technique.getChildNode( "shape" );
		if( !shapeNode.isEmpty() )
		{
			XMLNode hullNode = shapeNode.getChildNode("box");
			if ( !hullNode.isEmpty() )
			{
				shape = Box;
				if ( !hullNode.getChildNode("half_extents").isEmpty() )
				{					
					stringstream str(hullNode.getChildNode("half_extents").getText());
					str >> extents.x >> extents.y >> extents.z;
				}
			}
			else if ( !(hullNode = shapeNode.getChildNode("sphere")).isEmpty() )
			{
				shape = Sphere;
				if ( !hullNode.getChildNode("radius").isEmpty() )
					radius = (float) atof( hullNode.getChildNode("radius").getText() );
			}
			else
			{
				shape = Mesh;
				if ( !shapeNode.getChildNode("instance_geometry").isEmpty())
					geometry = shapeNode.getAttribute("url","");
			}
		}		
		else
			return false;
		return true;
	}
};



struct DaePhysicsModel
{
	string		id;
	string		name;
	vector<DaePhysicsRigidBody*> rigidBodies;

	~DaePhysicsModel()
	{
		for( unsigned int i = 0; i < rigidBodies.size(); ++i ) delete rigidBodies[i];
	}

	DaePhysicsRigidBody* findRigidBody( const string& id )
	{
		if ( id.empty() ) return 0x0;

		for( unsigned int i = 0; i < rigidBodies.size(); ++i )
		{
			if( rigidBodies[i]->id == id ) return rigidBodies[i];
		}
		return 0x0;
	}

	bool parse( const XMLNode &physicsNode )
	{
		id = physicsNode.getAttribute( "id", "" );
		if ( id == "" ) return false;
		name = physicsNode.getAttribute( "name", "" );
		
		int nodeItr = 0;
		XMLNode node2 = physicsNode.getChildNode( "rigid_body", nodeItr );
		while( !node2.isEmpty() )
		{
			DaePhysicsRigidBody *physic = new DaePhysicsRigidBody();
			if( physic->parse( node2 ) ) rigidBodies.push_back( physic );
			else delete physic;

			node2 = physicsNode.getChildNode( "rigid_body", ++nodeItr );
		}
		return true;
	}
};

struct DaeLibPhysicsModels
{
	vector< DaePhysicsModel * >	physics;


	~DaeLibPhysicsModels()
	{
		for( unsigned int i = 0; i < physics.size(); ++i ) delete physics[i];
	}


	DaePhysicsModel *findPhysicsModel( const string& id )
	{
		if( id.empty() ) return 0x0;
		for( unsigned int i = 0; i < physics.size(); ++i )
		{
			if( physics[i]->id == id ) return physics[i];
		}

		return 0x0;
	}

	
	bool parse( const XMLNode &rootNode )
	{
		XMLNode node1 = rootNode.getChildNode( "library_physics_models" );
		if( node1.isEmpty() ) return true;

		int nodeItr = 0;
		XMLNode node2 = node1.getChildNode( "physics_model", nodeItr );
		while( !node2.isEmpty() )
		{
			DaePhysicsModel *physic = new DaePhysicsModel();
			if( physic->parse( node2 ) ) physics.push_back( physic );
			else delete physic;

			node2 = node1.getChildNode( "physics_model", ++nodeItr );
		}
		
		return true;
	}
};