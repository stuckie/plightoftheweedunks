// MAYA Light Node Code -- Steven "Stuckie" Campbell
////////////////////////////////////////////////////

#ifndef _daeLibLights_H_
#define _daeLibLights_H_

#include "utXMLParser.h"
#include <string>
#include <vector>
using namespace std;


struct DaeLight
{
	string		id;
	string		name;
	string		lightColour;
	double		constant_attenuation;
    double		linear_attenuation;
    double		quadratic_attenuation;
    double		falloff_angle;
    double		falloff_exponent;
    double		intensity;
    double		outer_cone;
	float		r, g, b;
	bool		point;
	bool		directional;
	bool		spot;


	bool parse( const XMLNode &lightNode )
	{
		point = directional = spot = false;
		id = lightNode.getAttribute( "id", "" );
		if( id == "" ) return false;
		name = lightNode.getAttribute( "name", "" );

		XMLNode node2 = lightNode.getChildNode( "technique_common" );
		if( !node2.isEmpty() )
		{
			XMLNode node3 = node2.getChildNode( "directional" );
			if (!node3.isEmpty())
				directional = true;

			std::vector<float> colors;
			if( parseFloatArray(node3.getChildNode("color"),3,colors) )
			{
				r = colors[0];
				g = colors[1];
				b = colors[2];
			}

			node3 = node2.getChildNode( "spot" );
			if (!node3.isEmpty())
				spot = true;

			if( parseFloatArray(node3.getChildNode("color"),3,colors) )
			{
				r = colors[0];
				g = colors[1];
				b = colors[2];
			}

			node3 = node2.getChildNode( "point" );
			if (!node3.isEmpty())
				point = true;

			if( parseFloatArray(node3.getChildNode("color"),3,colors) )
			{
				r = colors[0];
				g = colors[1];
				b = colors[2];
			}
		}
		
		node2 = lightNode.getChildNode( "extra" );
		if( !node2.isEmpty() )
		{
			XMLNode node3 = node2.getChildNode("technique");
			if( strcmp( node3.getAttribute( "profile", "" ), "FCOLLADA" ) == 0 )
			{
				if( !node3.getChildNode( "constant_attenuation" ).isEmpty() &&
					node3.getChildNode( "constant_attenuation" ).getText() != 0x0 )
						constant_attenuation = atof(node3.getChildNode( "constant_attenuation" ).getText());


				if( !node3.getChildNode( "linear_attenuation" ).isEmpty() &&
					node3.getChildNode( "linear_attenuation" ).getText() != 0x0 )
						linear_attenuation = atof(node3.getChildNode( "linear_attenuation" ).getText());
				
				if( !node3.getChildNode( "quadratic_attenuation" ).isEmpty() &&
					node3.getChildNode( "quadratic_attenuation" ).getText() != 0x0 )
						quadratic_attenuation = atof(node3.getChildNode( "quadratic_attenuation" ).getText());


				if( !node3.getChildNode( "falloff_angle" ).isEmpty() &&
					node3.getChildNode( "falloff_angle" ).getText() != 0x0 )
						falloff_angle = atof(node3.getChildNode( "falloff_angle" ).getText());
				
				if( !node3.getChildNode( "falloff_exponent" ).isEmpty() &&
					node3.getChildNode( "falloff_exponent" ).getText() != 0x0 )
						falloff_exponent = atof(node3.getChildNode( "falloff_exponent" ).getText());
	

				if( !node3.getChildNode( "intensity" ).isEmpty() &&
					node3.getChildNode( "intensity" ).getText() != 0x0 )
						intensity = atof(node3.getChildNode( "intensity" ).getText());

				
				if( !node3.getChildNode( "outer_cone" ).isEmpty() &&
					node3.getChildNode( "outer_cone" ).getText() != 0x0 )
						outer_cone = atof(node3.getChildNode( "outer_cone" ).getText());

			}
		}

		return true;
	}
};


struct DaeLibLights
{
	vector< DaeLight * >	lights;


	~DaeLibLights()
	{
		for( unsigned int i = 0; i < lights.size(); ++i ) delete lights[i];
	}


	DaeLight *findLight( const string &id )
	{
		if( id == "" ) return 0x0;
		
		for( unsigned int i = 0; i < lights.size(); ++i )
		{
			if( lights[i]->id == id ) return lights[i];
		}

		return 0x0;
	}

	
	bool parse( const XMLNode &rootNode )
	{
		XMLNode node1 = rootNode.getChildNode( "library_lights" );
		if( node1.isEmpty() ) return true;

		int nodeItr2 = 0;
		XMLNode node2 = node1.getChildNode( "light", nodeItr2 );
		while( !node2.isEmpty() )
		{
			DaeLight *light = new DaeLight();
			if( light->parse( node2 ) ) lights.push_back( light );
			else delete light;

			node2 = node1.getChildNode( "light", ++nodeItr2 );
		}
		
		return true;
	}
};

#endif // _daeLibCameras_H_
