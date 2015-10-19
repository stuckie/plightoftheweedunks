// MAYA Camera Node Code -- Steven "Stuckie" Campbell
////////////////////////////////////////////////////

#ifndef _daeLibCameras_H_
#define _daeLibCameras_H_

#include "utXMLParser.h"
#include <string>
#include <vector>
using namespace std;


struct DaeCamera
{
	string		id;
	string		name;
	float		yfov;
	float		aspect;
	float		znear;
	float		zfar;


	bool parse( const XMLNode &camNode )
	{
		id = camNode.getAttribute( "id", "" );
		if( id == "" ) return false;
		name = camNode.getAttribute( "name", "" );

		XMLNode optics_node = camNode.getChildNode("optics");
		XMLNode technique_node = optics_node.getChildNode("technique_common");
		XMLNode perspective_node = technique_node.getChildNode("perspective");
		if( !perspective_node.isEmpty() )
		{
			yfov = getNodeFloat(perspective_node.getChildNode("yfov"),45.0f);
			aspect = getNodeFloat(perspective_node.getChildNode("aspect_ratio"),1.0f);
			znear = getNodeFloat(perspective_node.getChildNode("znear"),1.0f);
			zfar = getNodeFloat(perspective_node.getChildNode("zfar"),1000.0f);
		}

		return true;
	}
};


struct DaeLibCameras
{
	vector< DaeCamera * >	cameras;


	~DaeLibCameras()
	{
		for( unsigned int i = 0; i < cameras.size(); ++i ) delete cameras[i];
	}


	DaeCamera *findCamera( const string &id )
	{
		if( id == "" ) return 0x0;
		
		for( unsigned int i = 0; i < cameras.size(); ++i )
		{
			if( cameras[i]->id == id ) return cameras[i];
		}

		return 0x0;
	}

	
	bool parse( const XMLNode &rootNode )
	{
		XMLNode node1 = rootNode.getChildNode( "library_cameras" );
		if( node1.isEmpty() ) return true;

		int nodeItr2 = 0;
		XMLNode node2 = node1.getChildNode( "camera", nodeItr2 );
		while( !node2.isEmpty() )
		{
			DaeCamera *camera = new DaeCamera();
			if( camera->parse( node2 ) ) cameras.push_back( camera );
			else delete camera;

			node2 = node1.getChildNode( "camera", ++nodeItr2 );
		}
		
		return true;
	}
};

#endif // _daeLibCameras_H_
