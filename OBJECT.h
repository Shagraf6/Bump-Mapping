//////////////////////////////////////////////////////////////////////////////////////////
//	OBJECT.h
//	class declaration to create OBJECT with tangents
//	Downloaded from: www.paulsprojects.net
//	Created:	20th July 2002
//
//	Copyright (c) 2006, Paul Baker
//	Distributed under the New BSD Licence. (See accompanying file License.txt or copy at
//	http://www.paulsprojects.net/NewBSDLicense.txt)
//////////////////////////////////////////////////////////////////////////////////////////	

#ifndef TORUS_H
#define TORUS_H
#include "windows.h"
#include <glut.h>
//#include "VECTOR3D.h"
#include <stdio.h>
#include <GL\gl.h>
#include "Maths/Maths.h"

class VERTEX
{
public:
	VECTOR3D position;
	float s, t;
	VECTOR3D sTangent, tTangent;
	VECTOR3D normal;
	VECTOR3D tangentSpaceLight;
};

class OBJECT
{
public:
	int choice;
	OBJECT();
	~OBJECT();

	bool InitTri();
	bool InitSQ();
	bool InitRM();
	void Display();
	bool InitSQ1();

	bool InitTorus();

	int numVertices;
	int numIndices;

	unsigned int * indices;
	VERTEX * vertices;
};

const int torusPrecision=48;

//#endif	//TORUS_H

void OBJECT::Display()
{

	if (this->choice==1)
		InitTri();
	else if (this->choice==2)
		InitSQ();
}


OBJECT::OBJECT()
{
//	InitTorus();
	//Display();

}OBJECT::~OBJECT()
{
	if (indices)
		delete[] indices;
	indices = NULL;

	if (vertices)
		delete[] vertices;
	vertices = NULL;
}

bool OBJECT::InitTri()
{
	numVertices = 4;

	numIndices = 3;
	//indices = 4;
	vertices = new VERTEX[numVertices];
	if (!vertices)
	{
		printf("Unable to allocate memory for torus vertices\n");
		return false;
	}

	indices = new unsigned int[numIndices];

	if (!indices)
	{
		printf("Unable to allocate memory for torus indices\n");
		return false;
	}

	indices[0] = 0;
	indices[1] = 1;
	indices[2] = 2;

	vertices[0].position = VECTOR3D(2.0f, 2.5f, 0.0f);
	vertices[0].s = 0.0;
	vertices[0].t = 0.0;


	vertices[1].position = VECTOR3D(6.0f, 2.5f, 0.0f);
	vertices[1].s = 1.0;
	vertices[1].t = 0.0;


	vertices[2].position = VECTOR3D(4.0f, 6.0f, 0.0f);
	vertices[2].s = 0.5;
	vertices[2].t = 1.0;


	VECTOR3D edge1 = vertices[1].position - vertices[0].position;
	VECTOR3D edge2 = vertices[2].position - vertices[1].position;

	VECTOR2D deltaUV1, deltaUV2;

	deltaUV1.x = vertices[1].s - vertices[0].s;
	deltaUV1.y = vertices[1].t - vertices[0].t;
	deltaUV2.x = vertices[2].s - vertices[0].s;
	deltaUV2.y = vertices[2].t - vertices[0].t;

	VECTOR3D tangent1, bitangent1;
	VECTOR3D tangent2, bitangent2;
	VECTOR3D NORMAL;

	GLfloat f = 1.0f / (deltaUV1.x * deltaUV2.y - deltaUV2.x * deltaUV1.y);

	tangent1.x = f * (deltaUV2.y * edge1.x - deltaUV1.y * edge2.x);
	tangent1.y = f * (deltaUV2.y * edge1.y - deltaUV1.y * edge2.y);
	tangent1.z = f * (deltaUV2.y * edge1.z - deltaUV1.y * edge2.z);
	tangent1.Normalize();

	bitangent1.x = f * (-deltaUV2.x * edge1.x + deltaUV1.x * edge2.x);
	bitangent1.y = f * (-deltaUV2.x * edge1.y + deltaUV1.x * edge2.y);
	bitangent1.z = f * (-deltaUV2.x * edge1.z + deltaUV1.x * edge2.z);
	bitangent1.Normalize();

	vertices[0].sTangent = tangent1;
	vertices[1].sTangent = tangent1;
	vertices[2].sTangent = tangent1;

	vertices[0].tTangent = bitangent1;
	vertices[1].tTangent = bitangent1;
	vertices[2].tTangent = bitangent1;

	vertices[1].sTangent = tangent2;
	vertices[2].sTangent = tangent2;
	vertices[3].sTangent = tangent2;


	/*	vertices[1].tTangent = bitangent2;
	vertices[2].tTangent = bitangent2;
	vertices[3].tTangent = bitangent2;
	*/
	/*	vertices[0].normal = vertices[0].tTangent.CrossProduct(vertices[0].sTangent);
	vertices[1].normal = vertices[1].tTangent.CrossProduct(vertices[1].sTangent);
	vertices[2].normal = vertices[2].tTangent.CrossProduct(vertices[2].sTangent);
	vertices[3].normal = vertices[3].tTangent.CrossProduct(vertices[3].sTangent);
	*/
	vertices[0].normal = VECTOR3D(0.0f, 0.0f, 1.0f);
	vertices[1].normal = VECTOR3D(0.0f, 0.0f, 1.0f);
	vertices[2].normal = VECTOR3D(0.0f, 0.0f, 1.0f);
	//	vertices[3].normal = VECTOR3D(0.0f, 0.0f, 1.0f);



	return true;
}

bool OBJECT::InitSQ()
{
	numVertices = 4;

	numIndices = 6;
	//indices = 4;
	vertices = new VERTEX[numVertices];
	if (!vertices)
	{
		printf("Unable to allocate memory for torus vertices\n");
		return false;
	}

	indices = new unsigned int[numIndices];

	if (!indices)
	{
		printf("Unable to allocate memory for torus indices\n");
		return false;
	}

	indices[0] = 0;
	indices[1] = 1;
	indices[2] = 2;
	indices[3] = 0;
	indices[4] = 2;
	indices[5] = 3;

	vertices[0].position = VECTOR3D(2.0f, 6.0f, 0.0f);
	vertices[0].s = 0.0;
	vertices[0].t = 1.0;


	vertices[1].position = VECTOR3D(2.0f, 2.0f, 0.0f);
	vertices[1].s = 0.0;
	vertices[1].t = 0.0;


	vertices[2].position = VECTOR3D(6.0f, 2.0f, 0.0f);
	vertices[2].s = 1.0;
	vertices[2].t = 0.0;

	vertices[3].position = VECTOR3D(6.0f, 6.0f, 0.0f);
	vertices[3].s = 1.0;
	vertices[3].t = 1.0;

	VECTOR3D edge1 = vertices[1].position - vertices[0].position;
	VECTOR3D edge2 = vertices[2].position - vertices[1].position;

	VECTOR2D deltaUV1, deltaUV2;

	deltaUV1.x = vertices[1].s - vertices[0].s;
	deltaUV1.y = vertices[1].t - vertices[0].t;
	deltaUV2.x = vertices[2].s - vertices[0].s;
	deltaUV2.y = vertices[2].t - vertices[0].t;

	VECTOR3D tangent1, bitangent1;
	VECTOR3D tangent2, bitangent2;
	VECTOR3D NORMAL;

	GLfloat f = 1.0f / (deltaUV1.x * deltaUV2.y - deltaUV2.x * deltaUV1.y);

	tangent1.x = f * (deltaUV2.y * edge1.x - deltaUV1.y * edge2.x);
	tangent1.y = f * (deltaUV2.y * edge1.y - deltaUV1.y * edge2.y);
	tangent1.z = f * (deltaUV2.y * edge1.z - deltaUV1.y * edge2.z);
	tangent1.Normalize();

	bitangent1.x = f * (-deltaUV2.x * edge1.x + deltaUV1.x * edge2.x);
	bitangent1.y = f * (-deltaUV2.x * edge1.y + deltaUV1.x * edge2.y);
	bitangent1.z = f * (-deltaUV2.x * edge1.z + deltaUV1.x * edge2.z);
	bitangent1.Normalize();

	vertices[0].sTangent = tangent1;
	vertices[1].sTangent = tangent1;
	vertices[2].sTangent = tangent1;

	vertices[0].tTangent = bitangent1;
	vertices[1].tTangent = bitangent1;
	vertices[2].tTangent = bitangent1;

	// triangle 2
	//	 ----------


	edge1 = vertices[2].position - vertices[1].position;
    edge2 = vertices[3].position - vertices[2].position;

	deltaUV1.x = vertices[2].s - vertices[1].s;
	deltaUV1.y = vertices[2].t - vertices[1].t;

	deltaUV2.x = vertices[3].s - vertices[1].s;
	deltaUV2.y = vertices[3].t - vertices[1].t;

	f = 1.0f / (deltaUV1.x * deltaUV2.y - deltaUV2.x * deltaUV1.y);

	tangent2.x = f * (deltaUV2.y * edge1.x - deltaUV1.y * edge2.x);
	tangent2.y = f * (deltaUV2.y * edge1.y - deltaUV1.y * edge2.y);
	tangent2.z = f * (deltaUV2.y * edge1.z - deltaUV1.y * edge2.z);
	tangent2.Normalize();


	bitangent2.x = f * (-deltaUV2.x * edge1.x + deltaUV1.x * edge2.x);
	bitangent2.y = f * (-deltaUV2.x * edge1.y + deltaUV1.x * edge2.y);
	bitangent2.z = f * (-deltaUV2.x * edge1.z + deltaUV1.x * edge2.z);
	bitangent2.Normalize();


	vertices[1].sTangent = tangent2;
	vertices[2].sTangent = tangent2;
	vertices[3].sTangent = tangent2;


	vertices[1].tTangent = bitangent2;
	vertices[2].tTangent = bitangent2;
	vertices[3].tTangent = bitangent2;

	/*	vertices[0].normal = vertices[0].tTangent.CrossProduct(vertices[0].sTangent);
	vertices[1].normal = vertices[1].tTangent.CrossProduct(vertices[1].sTangent);
	vertices[2].normal = vertices[2].tTangent.CrossProduct(vertices[2].sTangent);
	vertices[3].normal = vertices[3].tTangent.CrossProduct(vertices[3].sTangent);
	*/
	vertices[0].normal = VECTOR3D(0.0f, 0.0f, 1.0f);
	vertices[1].normal = VECTOR3D(0.0f, 0.0f, 1.0f);
	vertices[2].normal = VECTOR3D(0.0f, 0.0f, 1.0f);
	vertices[3].normal = VECTOR3D(0.0f, 0.0f, 1.0f);

	return true;
}

bool OBJECT::InitRM()
{
	numVertices = 4;

	numIndices = 6;
	//indices = 4;
	vertices = new VERTEX[numVertices];
	if (!vertices)
	{
		printf("Unable to allocate memory for torus vertices\n");
		return false;
	}

	indices = new unsigned int[numIndices];

	if (!indices)
	{
		printf("Unable to allocate memory for torus indices\n");
		return false;
	}

	indices[0] = 0;
	indices[1] = 1;
	indices[2] = 2;
	indices[3] = 2;
	indices[4] = 3;
	indices[5] = 0;

	vertices[0].position = VECTOR3D(2.0f, 4.0f, 0.0f);
	vertices[0].s = 0.0;
	vertices[0].t = 1.0;


	vertices[1].position = VECTOR3D(4.0f, 2.0f, 0.0f);
	vertices[1].s = 0.0;
	vertices[1].t = 0.0;


	vertices[2].position = VECTOR3D(6.0f, 4.0f, 0.0f);
	vertices[2].s = 1.0;
	vertices[2].t = 0.0;

	vertices[3].position = VECTOR3D(4.0f, 6.0f, 0.0f);
	vertices[3].s = 1.0;
	vertices[3].t = 1.0;

	VECTOR3D edge1 = vertices[1].position - vertices[0].position;
	VECTOR3D edge2 = vertices[2].position - vertices[1].position;

	VECTOR2D deltaUV1, deltaUV2;

	deltaUV1.x = vertices[1].s - vertices[0].s;
	deltaUV1.y = vertices[1].t - vertices[0].t;
	deltaUV2.x = vertices[2].s - vertices[0].s;
	deltaUV2.y = vertices[2].t - vertices[0].t;

	VECTOR3D tangent1, bitangent1;
	VECTOR3D tangent2, bitangent2;
	VECTOR3D NORMAL;

	GLfloat f = 1.0f / (deltaUV1.x * deltaUV2.y - deltaUV2.x * deltaUV1.y);

	tangent1.x = f * (deltaUV2.y * edge1.x - deltaUV1.y * edge2.x);
	tangent1.y = f * (deltaUV2.y * edge1.y - deltaUV1.y * edge2.y);
	tangent1.z = f * (deltaUV2.y * edge1.z - deltaUV1.y * edge2.z);
	tangent1.Normalize();

	bitangent1.x = f * (-deltaUV2.x * edge1.x + deltaUV1.x * edge2.x);
	bitangent1.y = f * (-deltaUV2.x * edge1.y + deltaUV1.x * edge2.y);
	bitangent1.z = f * (-deltaUV2.x * edge1.z + deltaUV1.x * edge2.z);
	bitangent1.Normalize();

	vertices[0].sTangent = tangent1;
	vertices[1].sTangent = tangent1;
	vertices[2].sTangent = tangent1;

	vertices[0].tTangent = bitangent1;
	vertices[1].tTangent = bitangent1;
	vertices[2].tTangent = bitangent1;

	// triangle 2
	//	 ----------

	edge1 = vertices[2].position - vertices[1].position;
	 edge2 = vertices[3].position - vertices[2].position;
	deltaUV1.x = vertices[2].s - vertices[1].s;
	deltaUV1.y = vertices[2].t - vertices[1].t;

	deltaUV2.x = vertices[3].s - vertices[1].s;
	deltaUV2.y = vertices[3].t - vertices[1].t;

	f = 1.0f / (deltaUV1.x * deltaUV2.y - deltaUV2.x * deltaUV1.y);

	tangent2.x = f * (deltaUV2.y * edge1.x - deltaUV1.y * edge2.x);
	tangent2.y = f * (deltaUV2.y * edge1.y - deltaUV1.y * edge2.y);
	tangent2.z = f * (deltaUV2.y * edge1.z - deltaUV1.y * edge2.z);
	tangent2.Normalize();


	bitangent2.x = f * (-deltaUV2.x * edge1.x + deltaUV1.x * edge2.x);
	bitangent2.y = f * (-deltaUV2.x * edge1.y + deltaUV1.x * edge2.y);
	bitangent2.z = f * (-deltaUV2.x * edge1.z + deltaUV1.x * edge2.z);
	bitangent2.Normalize();


	vertices[1].sTangent = tangent2;
	vertices[2].sTangent = tangent2;
	vertices[3].sTangent = tangent2;


	vertices[1].tTangent = bitangent2;
	vertices[2].tTangent = bitangent2;
	vertices[3].tTangent = bitangent2;

	/*	vertices[0].normal = vertices[0].tTangent.CrossProduct(vertices[0].sTangent);
	vertices[1].normal = vertices[1].tTangent.CrossProduct(vertices[1].sTangent);
	vertices[2].normal = vertices[2].tTangent.CrossProduct(vertices[2].sTangent);
	vertices[3].normal = vertices[3].tTangent.CrossProduct(vertices[3].sTangent);
	*/
	vertices[0].normal = VECTOR3D(0.0f, 0.0f, 1.0f);
	vertices[1].normal = VECTOR3D(0.0f, 0.0f, 1.0f);
	vertices[2].normal = VECTOR3D(0.0f, 0.0f, 1.0f);
	vertices[3].normal = VECTOR3D(0.0f, 0.0f, 1.0f);

	return true;
}


bool OBJECT::InitSQ1()
{
	numVertices = 8;

	numIndices = 6*8;
	//indices = 4;
	vertices = new VERTEX[numVertices];
	if (!vertices)
	{
		printf("Unable to allocate memory for torus vertices\n");
		return false;
	}

	indices = new unsigned int[numIndices];

	if (!indices)
	{
		printf("Unable to allocate memory for torus indices\n");
		return false;
	}

	indices[0] = 0;
	indices[1] = 1;
	indices[2] = 2;
	indices[3] = 0;
	indices[4] = 2;
	indices[5] = 3;


	indices[6] = 2;
	indices[7] = 4;
	indices[8] = 5;
	indices[9] = 2;
	indices[10] = 3;
	indices[11] = 5;



	indices[12] = 1;
	indices[13] = 2;
	indices[14] = 4;
	indices[15] = 1;
	indices[16] = 6;
	indices[17] = 4;

	indices[18] = 0;
	indices[19] = 3;
	indices[20] = 5;
	indices[21] = 0;
	indices[22] = 7;
	indices[23] = 5;


	vertices[0].position = VECTOR3D(-1.0f, -1.0f, -1.0f);
	vertices[0].s = 0.0;
	vertices[0].t = 1.0;


	vertices[1].position = VECTOR3D(-1.0f, -1.0f, 1.0f);
	vertices[1].s = 0.0;
	vertices[1].t = 0.0;


	vertices[2].position = VECTOR3D(-1.0f, 1.0f, -1.0f);
	vertices[2].s = 1.0;
	vertices[2].t = 0.0;

	vertices[3].position = VECTOR3D(-1.0f, 1.0f, 1.0f);
	vertices[3].s = 1.0;
	vertices[3].t = 1.0;


	vertices[4].position = VECTOR3D(1.0f, -1.0f, -1.0f);
	vertices[4].s = 0.0;
	vertices[4].t = 1.0;


	vertices[5].position = VECTOR3D(1.0f, -1.0f, 1.0f);
	vertices[5].s = 0.0;
	vertices[5].t = 0.0;


	vertices[6].position = VECTOR3D(1.0f, 1.0f, -1.0f);
	vertices[6].s = 1.0;
	vertices[6].t = 0.0;

	vertices[7].position = VECTOR3D(1.0f, 1.0f, 1.0f);
	vertices[7].s = 1.0;
	vertices[7].t = 1.0;




	/*vertices[0].position = VECTOR3D(.1f, .1f, 0.1f);
	vertices[0].s = 0.0;
	vertices[0].t = 1.0;


	vertices[1].position = VECTOR3D(0.1f, 0.1f, 0.1f);
	vertices[1].s = 0.0;
	vertices[1].t = 0.0;


	vertices[2].position = VECTOR3D(0.1f, 0.1f, 0.1f);
	vertices[2].s = 1.0;
	vertices[2].t = 0.0;

	vertices[3].position = VECTOR3D(1.0f, 0.1f, 0.1f);
	vertices[3].s = 1.0;
	vertices[3].t = 1.0;


	vertices[4].position = VECTOR3D(1.0f, 1.0f, 1.0f);
	vertices[4].s = 0.0;
	vertices[4].t = 1.0;


	vertices[5].position = VECTOR3D(1.0f, 1.0f, 1.0f);
	vertices[5].s = 0.0;
	vertices[5].t = 0.0;


	vertices[6].position = VECTOR3D(1.0f, 1.0f, 1.0f);
	vertices[6].s = 1.0;
	vertices[6].t = 0.0;

	vertices[7].position = VECTOR3D(1.0f, 1.0f, 1.0f);
	vertices[7].s = 1.0;
	vertices[7].t = 1.0;


*/
	/*Points[0].set(-1.0, -1.0, -1.0);
	Points[1].set(-1.0, -1.0, 1.0);
	Points[2].set(-1.0, 1.0, -1.0);
	Points[3].set(-1.0, 1.0, 1.0);
	
	Points[4].set(1.0, -1.0, -1.0);
	Points[5].set(1.0, -1.0, 1.0);
	Points[6].set(1.0, 1.0, -1.0);
	Points[7].set(1.0, 1.0, 1.0);
*/


	VECTOR3D edge1 = vertices[1].position - vertices[0].position;
	VECTOR3D edge2 = vertices[2].position - vertices[1].position;

	VECTOR2D deltaUV1, deltaUV2;

	deltaUV1.x = vertices[1].s - vertices[0].s;
	deltaUV1.y = vertices[1].t - vertices[0].t;
	deltaUV2.x = vertices[2].s - vertices[0].s;
	deltaUV2.y = vertices[2].t - vertices[0].t;

	VECTOR3D tangent1, bitangent1;
	VECTOR3D tangent2, bitangent2;
	VECTOR3D NORMAL;

	GLfloat f = 1.0f / (deltaUV1.x * deltaUV2.y - deltaUV2.x * deltaUV1.y);

	tangent1.x = f * (deltaUV2.y * edge1.x - deltaUV1.y * edge2.x);
	tangent1.y = f * (deltaUV2.y * edge1.y - deltaUV1.y * edge2.y);
	tangent1.z = f * (deltaUV2.y * edge1.z - deltaUV1.y * edge2.z);
	tangent1.Normalize();

	bitangent1.x = f * (-deltaUV2.x * edge1.x + deltaUV1.x * edge2.x);
	bitangent1.y = f * (-deltaUV2.x * edge1.y + deltaUV1.x * edge2.y);
	bitangent1.z = f * (-deltaUV2.x * edge1.z + deltaUV1.x * edge2.z);
	bitangent1.Normalize();

	vertices[0].sTangent = tangent1;
	vertices[1].sTangent = tangent1;
	vertices[2].sTangent = tangent1;

	vertices[0].tTangent = bitangent1;
	vertices[1].tTangent = bitangent1;
	vertices[2].tTangent = bitangent1;

	// triangle 2
	//	 ----------

	edge1 = vertices[2].position - vertices[1].position;
	edge2 = vertices[3].position - vertices[2].position;

	deltaUV1.x = vertices[2].s - vertices[1].s;
	deltaUV1.y = vertices[2].t - vertices[1].t;

	deltaUV2.x = vertices[3].s - vertices[1].s;
	deltaUV2.y = vertices[3].t - vertices[1].t;

	f = 1.0f / (deltaUV1.x * deltaUV2.y - deltaUV2.x * deltaUV1.y);

	tangent2.x = f * (deltaUV2.y * edge1.x - deltaUV1.y * edge2.x);
	tangent2.y = f * (deltaUV2.y * edge1.y - deltaUV1.y * edge2.y);
	tangent2.z = f * (deltaUV2.y * edge1.z - deltaUV1.y * edge2.z);
	tangent2.Normalize();


	bitangent2.x = f * (-deltaUV2.x * edge1.x + deltaUV1.x * edge2.x);
	bitangent2.y = f * (-deltaUV2.x * edge1.y + deltaUV1.x * edge2.y);
	bitangent2.z = f * (-deltaUV2.x * edge1.z + deltaUV1.x * edge2.z);
	bitangent2.Normalize();


	vertices[1].sTangent = tangent2;
	vertices[2].sTangent = tangent2;
	vertices[3].sTangent = tangent2;


	vertices[1].tTangent = bitangent2;
	vertices[2].tTangent = bitangent2;
	vertices[3].tTangent = bitangent2;

	/*	vertices[0].normal = vertices[0].tTangent.CrossProduct(vertices[0].sTangent);
	vertices[1].normal = vertices[1].tTangent.CrossProduct(vertices[1].sTangent);
	vertices[2].normal = vertices[2].tTangent.CrossProduct(vertices[2].sTangent);
	vertices[3].normal = vertices[3].tTangent.CrossProduct(vertices[3].sTangent);
	*/
	vertices[0].normal = VECTOR3D(0.0f, 0.0f, 1.0f);
	vertices[1].normal = VECTOR3D(0.0f, 0.0f, 1.0f);
	vertices[2].normal = VECTOR3D(0.0f, 0.0f, 1.0f);
	vertices[3].normal = VECTOR3D(0.0f, 0.0f, 1.0f);

	vertices[4].normal = VECTOR3D(0.0f, 0.0f, 1.0f);
	vertices[5].normal = VECTOR3D(0.0f, 0.0f, 1.0f);
	vertices[6].normal = VECTOR3D(0.0f, 0.0f, 1.0f);
	vertices[7].normal = VECTOR3D(0.0f, 0.0f, 1.0f);






//face 2

	edge1 = vertices[4].position - vertices[2].position;
	edge2 = vertices[5].position - vertices[4].position;

//	VECTOR2D deltaUV1, deltaUV2;

	deltaUV1.x = vertices[4].s - vertices[2].s;
	deltaUV1.y = vertices[4].t - vertices[2].t;
	deltaUV2.x = vertices[5].s - vertices[2].s;
	deltaUV2.y = vertices[5].t - vertices[2].t;

	//VECTOR3D tangent1, bitangent1;
	//VECTOR3D tangent2, bitangent2;
	//VECTOR3D NORMAL;

 f = 1.0f / (deltaUV1.x * deltaUV2.y - deltaUV2.x * deltaUV1.y);

	tangent1.x = f * (deltaUV2.y * edge1.x - deltaUV1.y * edge2.x);
	tangent1.y = f * (deltaUV2.y * edge1.y - deltaUV1.y * edge2.y);
	tangent1.z = f * (deltaUV2.y * edge1.z - deltaUV1.y * edge2.z);
	tangent1.Normalize();

	bitangent1.x = f * (-deltaUV2.x * edge1.x + deltaUV1.x * edge2.x);
	bitangent1.y = f * (-deltaUV2.x * edge1.y + deltaUV1.x * edge2.y);
	bitangent1.z = f * (-deltaUV2.x * edge1.z + deltaUV1.x * edge2.z);
	bitangent1.Normalize();

	vertices[2].sTangent = tangent1;
	vertices[4].sTangent = tangent1;
	vertices[5].sTangent = tangent1;

	vertices[2].tTangent = bitangent1;
	vertices[4].tTangent = bitangent1;
	vertices[5].tTangent = bitangent1;

	// triangle 2
	//	 ----------
	edge1 = vertices[3].position - vertices[2].position;
	edge2 = vertices[5].position - vertices[3].position;


	deltaUV1.x = vertices[3].s - vertices[2].s;
	deltaUV1.y = vertices[3].t - vertices[2].t;

	deltaUV2.x = vertices[5].s - vertices[2].s;
	deltaUV2.y = vertices[5].t - vertices[2].t;

	f = 1.0f / (deltaUV1.x * deltaUV2.y - deltaUV2.x * deltaUV1.y);

	tangent2.x = f * (deltaUV2.y * edge1.x - deltaUV1.y * edge2.x);
	tangent2.y = f * (deltaUV2.y * edge1.y - deltaUV1.y * edge2.y);
	tangent2.z = f * (deltaUV2.y * edge1.z - deltaUV1.y * edge2.z);
	tangent2.Normalize();


	bitangent2.x = f * (-deltaUV2.x * edge1.x + deltaUV1.x * edge2.x);
	bitangent2.y = f * (-deltaUV2.x * edge1.y + deltaUV1.x * edge2.y);
	bitangent2.z = f * (-deltaUV2.x * edge1.z + deltaUV1.x * edge2.z);
	bitangent2.Normalize();



	vertices[2].sTangent = tangent2;
	vertices[3].sTangent = tangent2;
	vertices[5].sTangent = tangent2;


	vertices[2].tTangent = bitangent2;
	vertices[3].tTangent = bitangent2;
	vertices[5].tTangent = bitangent2;

	//face 3


	edge1 = vertices[2].position - vertices[1].position;
	edge2 = vertices[4].position - vertices[2].position;

	//	VECTOR2D deltaUV1, deltaUV2;

	deltaUV1.x = vertices[2].s - vertices[1].s;
	deltaUV1.y = vertices[2].t - vertices[1].t;
	deltaUV2.x = vertices[4].s - vertices[1].s;
	deltaUV2.y = vertices[4].t - vertices[1].t;

	//VECTOR3D tangent1, bitangent1;
	//VECTOR3D tangent2, bitangent2;
	//VECTOR3D NORMAL;

	f = 1.0f / (deltaUV1.x * deltaUV2.y - deltaUV2.x * deltaUV1.y);

	tangent1.x = f * (deltaUV2.y * edge1.x - deltaUV1.y * edge2.x);
	tangent1.y = f * (deltaUV2.y * edge1.y - deltaUV1.y * edge2.y);
	tangent1.z = f * (deltaUV2.y * edge1.z - deltaUV1.y * edge2.z);
	tangent1.Normalize();

	bitangent1.x = f * (-deltaUV2.x * edge1.x + deltaUV1.x * edge2.x);
	bitangent1.y = f * (-deltaUV2.x * edge1.y + deltaUV1.x * edge2.y);
	bitangent1.z = f * (-deltaUV2.x * edge1.z + deltaUV1.x * edge2.z);
	bitangent1.Normalize();

	vertices[1].sTangent = tangent1;
	vertices[2].sTangent = tangent1;
	vertices[4].sTangent = tangent1;

	vertices[1].tTangent = bitangent1;
	vertices[2].tTangent = bitangent1;
	vertices[4].tTangent = bitangent1;

	// triangle 2
	//	 ----------
	edge1 = vertices[6].position - vertices[1].position;
	edge2 = vertices[4].position - vertices[6].position;


	deltaUV1.x = vertices[6].s - vertices[1].s;
	deltaUV1.y = vertices[6].t - vertices[1].t;

	deltaUV2.x = vertices[4].s - vertices[1].s;
	deltaUV2.y = vertices[4].t - vertices[1].t;

	f = 1.0f / (deltaUV1.x * deltaUV2.y - deltaUV2.x * deltaUV1.y);

	tangent2.x = f * (deltaUV2.y * edge1.x - deltaUV1.y * edge2.x);
	tangent2.y = f * (deltaUV2.y * edge1.y - deltaUV1.y * edge2.y);
	tangent2.z = f * (deltaUV2.y * edge1.z - deltaUV1.y * edge2.z);
	tangent2.Normalize();


	bitangent2.x = f * (-deltaUV2.x * edge1.x + deltaUV1.x * edge2.x);
	bitangent2.y = f * (-deltaUV2.x * edge1.y + deltaUV1.x * edge2.y);
	bitangent2.z = f * (-deltaUV2.x * edge1.z + deltaUV1.x * edge2.z);
	bitangent2.Normalize();





	vertices[1].sTangent = tangent2;
	vertices[6].sTangent = tangent2;
	vertices[4].sTangent = tangent2;


	vertices[1].tTangent = bitangent2;
	vertices[6].tTangent = bitangent2;
	vertices[4].tTangent = bitangent2;

	//face 4


	edge1 = vertices[3].position - vertices[0].position;
	edge2 = vertices[5].position - vertices[3].position;

	//	VECTOR2D deltaUV1, deltaUV2;

	deltaUV1.x = vertices[3].s - vertices[0].s;
	deltaUV1.y = vertices[3].t - vertices[0].t;
	deltaUV2.x = vertices[5].s - vertices[0].s;
	deltaUV2.y = vertices[5].t - vertices[0].t;

	//VECTOR3D tangent1, bitangent1;
	//VECTOR3D tangent2, bitangent2;
	//VECTOR3D NORMAL;

	f = 1.0f / (deltaUV1.x * deltaUV2.y - deltaUV2.x * deltaUV1.y);

	tangent1.x = f * (deltaUV2.y * edge1.x - deltaUV1.y * edge2.x);
	tangent1.y = f * (deltaUV2.y * edge1.y - deltaUV1.y * edge2.y);
	tangent1.z = f * (deltaUV2.y * edge1.z - deltaUV1.y * edge2.z);
	tangent1.Normalize();

	bitangent1.x = f * (-deltaUV2.x * edge1.x + deltaUV1.x * edge2.x);
	bitangent1.y = f * (-deltaUV2.x * edge1.y + deltaUV1.x * edge2.y);
	bitangent1.z = f * (-deltaUV2.x * edge1.z + deltaUV1.x * edge2.z);
	bitangent1.Normalize();

	vertices[0].sTangent = tangent1;
	vertices[3].sTangent = tangent1;
	vertices[5].sTangent = tangent1;

	vertices[0].tTangent = bitangent1;
	vertices[3].tTangent = bitangent1;
	vertices[5].tTangent = bitangent1;

	// triangle 2
	//	 ----------
	edge1 = vertices[7].position - vertices[0].position;
	edge2 = vertices[5].position - vertices[7].position;


	deltaUV1.x = vertices[7].s - vertices[0].s;
	deltaUV1.y = vertices[7].t - vertices[0].t;

	deltaUV2.x = vertices[5].s - vertices[0].s;
	deltaUV2.y = vertices[5].t - vertices[0].t;

	f = 1.0f / (deltaUV1.x * deltaUV2.y - deltaUV2.x * deltaUV1.y);

	tangent2.x = f * (deltaUV2.y * edge1.x - deltaUV1.y * edge2.x);
	tangent2.y = f * (deltaUV2.y * edge1.y - deltaUV1.y * edge2.y);
	tangent2.z = f * (deltaUV2.y * edge1.z - deltaUV1.y * edge2.z);
	tangent2.Normalize();


	bitangent2.x = f * (-deltaUV2.x * edge1.x + deltaUV1.x * edge2.x);
	bitangent2.y = f * (-deltaUV2.x * edge1.y + deltaUV1.x * edge2.y);
	bitangent2.z = f * (-deltaUV2.x * edge1.z + deltaUV1.x * edge2.z);
	bitangent2.Normalize();

	vertices[0].sTangent = tangent2;
	vertices[7].sTangent = tangent2;
	vertices[5].sTangent = tangent2;


	vertices[0].tTangent = bitangent2;
	vertices[7].tTangent = bitangent2;
	vertices[5].tTangent = bitangent2;

	return true;
}
//
//bool OBJECT::InitTorus()
//{
//	numVertices = (torusPrecision + 1)*(torusPrecision + 1);
//	numIndices = 2 * torusPrecision*torusPrecision * 3;
//
//	vertices = new VERTEX[numVertices];
//	if (!vertices)
//	{
//		printf("Unable to allocate memory for OBJECT vertices\n");
//		return false;
//	}
//
//	indices = new unsigned int[numIndices];
//	if (!indices)
//	{
//		printf("Unable to allocate memory for OBJECT indices\n");
//		return false;
//	}
//
//	//calculate the first ring - inner radius 4, outer radius 1.5
//	for (int i = 0; i<torusPrecision + 1; i++)
//	{
//		vertices[i].position = VECTOR3D(1.5f, 0.0f, 0.0f).GetRotatedZ(i*360.0f / torusPrecision) +
//			VECTOR3D(4.0f, 0.0f, 0.0f);
//		float x = vertices[i].position.GetX();
//		float y = vertices[i].position.GetY();
//		float z = vertices[i].position.GetZ();
//
//
//		printf("x:", x);
//		printf("y:", y);
//		printf("z:", z);
//
//		vertices[i].s = 0.0f;
//		vertices[i].t = (float)i / torusPrecision;
//
//		vertices[i].sTangent.Set(0.0f, 0.0f, -1.0f);
//		vertices[i].tTangent = VECTOR3D(0.0f, -1.0f, 0.0f).GetRotatedZ(i*360.0f / torusPrecision);
//		vertices[i].normal = vertices[i].tTangent.
//			CrossProduct(vertices[i].sTangent);
//	}
//
//	//rotate this to get other rings
//	for (int ring = 1; ring<torusPrecision + 1; ring++)
//	{
//		for (int i = 0; i<torusPrecision + 1; i++)
//		{
//			vertices[ring*(torusPrecision + 1) + i].position = vertices[i].position.GetRotatedY(ring*360.0f / torusPrecision);
//			/*
//			float x = vertices[i].position.GetX();
//			float y = vertices[i].position.GetY();
//			float z = vertices[i].position.GetZ();
//
//
//			printf("x:", x);
//			printf("y:", y);
//			printf("z:", z);
//*/
//			vertices[ring*(torusPrecision + 1) + i].s = 2.0f*ring / torusPrecision;
//			vertices[ring*(torusPrecision + 1) + i].t = vertices[i].t;
//
//			vertices[ring*(torusPrecision + 1) + i].sTangent = vertices[i].sTangent.GetRotatedY(ring*360.0f / torusPrecision);
//			vertices[ring*(torusPrecision + 1) + i].tTangent = vertices[i].tTangent.GetRotatedY(ring*360.0f / torusPrecision);
//			vertices[ring*(torusPrecision + 1) + i].normal = vertices[i].normal.GetRotatedY(ring*360.0f / torusPrecision);
//		}
//	}
//
//	//calculate the indices
//	for (int ring = 0; ring<torusPrecision; ring++)
//	{
//		for (int i = 0; i<torusPrecision; i++)
//		{
//			indices[((ring*torusPrecision + i) * 2) * 3 + 0] = ring*(torusPrecision + 1) + i;
//			indices[((ring*torusPrecision + i) * 2) * 3 + 1] = (ring + 1)*(torusPrecision + 1) + i;
//			indices[((ring*torusPrecision + i) * 2) * 3 + 2] = ring*(torusPrecision + 1) + i + 1;
//			indices[((ring*torusPrecision + i) * 2 + 1) * 3 + 0] = ring*(torusPrecision + 1) + i + 1;
//			indices[((ring*torusPrecision + i) * 2 + 1) * 3 + 1] = (ring + 1)*(torusPrecision + 1) + i;
//			indices[((ring*torusPrecision + i) * 2 + 1) * 3 + 2] = (ring + 1)*(torusPrecision + 1) + i + 1;
//		}
//	}
//
//	return true;
//}
#endif	//TORUS_H
