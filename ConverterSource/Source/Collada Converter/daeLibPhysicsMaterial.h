#pragma once

#include "utXMLParser.h"
#include <string>
#include <vector>
using namespace std;


struct DaePhysicsMaterial
{
	string		id;
	string		name;
	float		dynamic_friction;
	float		restitution;
	float		static_friction;


	bool parse( const XMLNode &physicNode )
	{
		id = physicNode.getAttribute( "id", "" );
		if ( id == "" ) return false;
		name = physicNode.getAttribute( "name", "" );
		
		if( !physicNode.getChildNode( "dynamic_friction" ).isEmpty() )
			dynamic_friction = (float) atof(physicNode.getChildNode( "dynamic_friction" ).getText());
		else
			return false;
		if( !physicNode.getChildNode( "restitution" ).isEmpty() )
			restitution = (float) atof(physicNode.getChildNode( "restitution" ).getText());
		else
			return false;
		if( !physicNode.getChildNode( "static_friction" ).isEmpty() )
			static_friction = (float) atof(physicNode.getChildNode( "static_friction" ).getText());
		else
			return false;
		return true;
	}
};


struct DaeLibPhysicsMaterials
{
	vector< DaePhysicsMaterial * >	physics;


	~DaeLibPhysicsMaterials()
	{
		for( unsigned int i = 0; i < physics.size(); ++i ) delete physics[i];
	}


	DaePhysicsMaterial *findPhysicsMaterial( string id )
	{
		if( id == "" ) return 0x0;
		
		for( unsigned int i = 0; i < physics.size(); ++i )
		{
			if( physics[i]->id == id ) return physics[i];
		}

		return 0x0;
	}

	
	bool parse( const XMLNode &rootNode )
	{
		XMLNode node1 = rootNode.getChildNode( "library_physics_materials" );
		if( !node1.isEmpty() ) return true;

		int nodeItr = 0;
		XMLNode node2 = node1.getChildNode( "physics_material", nodeItr );
		while( !node2.isEmpty() )
		{
			DaePhysicsMaterial *physic = new DaePhysicsMaterial();
			if( physic->parse( node2 ) ) physics.push_back( physic );
			else delete physic;

			node2 = node1.getChildNode( "physics_material", ++nodeItr );
		}
		
		return true;
	}
};