#pragma once

#include "utXMLParser.h"
#include <string>
#include <vector>
#include <map>
#include "utils.h"
using namespace std;


struct DaePhysicsModelRef
{
	string model;
	map<string, string> rigidBodySceneNodeMap;

	bool parse( const XMLNode &physicNode )
	{
		model = physicNode.getAttribute( "url", "" );
		XMLNode node2 = physicNode.getChildNode( "instance_rigid_body" );
		while( !node2.isEmpty() )
		{
			rigidBodySceneNodeMap[node2.getAttribute("target","")] = node2.getAttribute("body","");
			node2 = node2.getChildNode( "instance_rigid_body" );
		}
		return true;
	}
};

struct DaePhysicsScene
{
	string		id;
	string		name;
	vector<DaePhysicsModelRef*> models;

	~DaePhysicsScene()
	{
		for( unsigned int i = 0; i < models.size(); ++i ) delete models[i];
	}

	bool parse( const XMLNode &physicNode )
	{
		id = physicNode.getAttribute( "id", "" );
		if ( id == "" ) return false;
		name = physicNode.getAttribute( "name", "" );
		
		XMLNode node2 = physicNode.getChildNode( "instance_physics_model" );
		while( !node2.isEmpty() )
		{
			DaePhysicsModelRef *physic = new DaePhysicsModelRef();
			if( physic->parse( node2 ) ) models.push_back( physic );
			else delete physic;

			node2 = node2.getChildNode( "instance_physics_model" );
		}
		return true;
	}
};


struct DaeLibPhysicsScenes
{
	vector< DaePhysicsScene * >	physicScenes;


	~DaeLibPhysicsScenes()
	{
		for( unsigned int i = 0; i < physicScenes.size(); ++i ) delete physicScenes[i];
	}


	DaePhysicsScene *findPhysicsScene( string id )
	{
		if( id == "" ) return 0x0;
		
		for( unsigned int i = 0; i < physicScenes.size(); ++i )
		{
			if( physicScenes[i]->id == id ) 
			{
				return physicScenes[i];
			}
		}

		return 0x0;
	}

	
	bool parse( const XMLNode &rootNode )
	{
		XMLNode node1 = rootNode.getChildNode( "library_physics_scenes" );
		if( node1.isEmpty() ) return true;

		int nodeItr = 0;
		XMLNode node2 = node1.getChildNode( "physics_scene", nodeItr );
		while( !node2.isEmpty() )
		{
			DaePhysicsScene *physic = new DaePhysicsScene();
			if( physic->parse( node2 ) ) physicScenes.push_back( physic );
			else delete physic;

			node2 = node1.getChildNode( "physics_scene", ++nodeItr );
		}
		
		return true;
	}
};