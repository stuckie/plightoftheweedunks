// *************************************************************************************************
//
// Horde3D
//   Next-Generation Graphics Engine
// --------------------------------------
// Copyright (C) 2006-2008 Nicolas Schulz
//
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
//
// *************************************************************************************************

#include "utils.h"
#include "utPlatform.h"
#include <iostream>
using namespace std;

#ifdef PLATFORM_WIN
#   define WIN32_LEAN_AND_MEAN 1
#	include <windows.h>
#endif


bool parseString( char *s, unsigned int &pos, string &token )
{
	token = "";
	token.reserve( 16 );
	
	s += pos;
	
	// End of string?
	if( *s == 0x0 ) return false;
	
	// Skip whitespaces
	while( *s != 0x0 )
	{
		if (strchr(" \t\n\r", *s) == 0x0) break;
		++s; ++pos;
	}

	// End of string?
	if( *s == 0x0 ) return false;

	// Copy token
	while (*s != 0x0)
	{
		if (strchr(" \t\n\r", *s) != 0x0) break;
		
		token += *s++; ++pos;
	}

	return true;
}


bool parseFloat( char *s, unsigned int &pos, float &value )
{
	string token;
	
	if( !parseString( s, pos, token ) ) return false;

	value = (float)atof( token.c_str() );

	return true;
}


bool parseUInt( char *s, unsigned int &pos, unsigned int &value )
{
	string token;
	
	if( !parseString( s, pos, token ) ) return false;

	value = (unsigned int)atoi( token.c_str() );

	return true;
}


void removeGate( string &s )
{
	if( s.length() == 0 ) return;

	if( s[0] == '#' ) s = s.substr( 1, s.length() - 1 );
}


string extractFileName( const string &fullPath, bool extension )
{
	int first = 0, last = (int)fullPath.length() - 1;
	
	for( int i = last; i >= 0; --i )
	{
		if( fullPath[i] == '.' )
		{
			last = i;
		}
		else if( fullPath[i] == '\\' || fullPath[i] == '/' )
		{
			first = i + 1;
			break;
		}
	}

	if( extension )
		return fullPath.substr( first, fullPath.length() - first );
	else
		return fullPath.substr( first, last - first );
}


string extractFilePath( const string &fullPath )
{
	int last = (int)fullPath.length() - 1;
	
	for( int i = last; i >= 0; --i )
	{
		if( fullPath[i] == '\\' || fullPath[i] == '/' )
		{
			last = i;
			break;
		}
	}

	return fullPath.substr( 0, last );
}


void log( const string &msg )
{
	cout << msg << endl;
	
	#ifdef PLATFORM_WIN
	OutputDebugString( msg.c_str() );
	OutputDebugString( "\n" );
	#endif
}


Matrix4f makeMatrix4f( float *floatArray16, bool y_up )
{
	Matrix4f mat( floatArray16 );
	mat = mat.transposed();

	// Flip matrix if necessary
	if( !y_up )
	{
		// Swap y/z rows
		swap( mat.c[0][1], mat.c[0][2] );
		swap( mat.c[1][1], mat.c[1][2] );
		swap( mat.c[2][1], mat.c[2][2] );
		swap( mat.c[3][1], mat.c[3][2] );

		// Swap y/z columns
		swap( mat.c[1][0], mat.c[2][0] );
		swap( mat.c[1][1], mat.c[2][1] );
		swap( mat.c[1][2], mat.c[2][2] );
		swap( mat.c[1][3], mat.c[2][3] );

		// Invert z-axis to make system right-handed again
		// (The swapping above results in a left-handed system)
		mat.c[0][2] *= -1;
		mat.c[1][2] *= -1;
		mat.c[3][2] *= -1;
		mat.c[2][0] *= -1;
		mat.c[2][1] *= -1;
		mat.c[2][3] *= -1;
	}

	return mat;
}

float getNodeFloat(XMLNode& node, float default)
{
	float f = default;
	if( !node.isEmpty() )
	{
		unsigned int pos = 0;
		char* s = (char*)node.getText();
		if( s )
		{
			parseFloat( s, pos, f );
		}
	}
	return f;
}

bool getNodeBool(XMLNode& node, bool default)
{
	bool f = default;
	if( !node.isEmpty() )
	{
		unsigned int pos = 0;
		char* s = (char*)node.getText();
		if( s )
		{
			if( strcmp(s,"1")==0 || strcmp(s,"true")==0 ) f = true;
			else f = false;
		}
	}
	return f;
}

string getNodeString(XMLNode& node, const string& default)
{
	string f = default;
	if( !node.isEmpty() )
	{
		unsigned int pos = 0;
		char* s = (char*)node.getText();
		if( s )
		{
			f = string(s);
		}
	}
	return f;
}

unsigned int getNodeUInt(XMLNode& node, unsigned int default)
{
	unsigned int f = default;
	if( !node.isEmpty() )
	{
		unsigned int pos = 0;
		char* s = (char*)node.getText();
		if( s )
		{
			parseUInt( s, pos, f );
		}
	}
	return f;
}


bool parseFloatArray(XMLNode& node, unsigned int count, std::vector<float>& array)
{
	if( !node.isEmpty() )
	{
		// Parse data
		unsigned int pos = 0;
		char* s = (char*)node.getText();
		if( s )
		{
			for( unsigned int i=0; i<count; ++i )
			{
				float f;
				parseFloat( s, pos, f );
				array.push_back( f );
			}
		}
	}
	return count==array.size();
}

bool parseStringArray(XMLNode& node, unsigned int count, std::vector<std::string>& array)
{
	if( !node.isEmpty() )
	{
		// Parse data
		unsigned int pos = 0;
		char* s = (char*)node.getText();
		if( s )
		{
			for( unsigned int i=0; i<count; ++i )
			{
				string name;
				parseString( s, pos, name );
				array.push_back( name );
			}
		}
	}
	return count==array.size();
}
