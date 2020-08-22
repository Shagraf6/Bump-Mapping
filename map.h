#include <windows.h>
#include <stdio.h>
#include <glut.h>
#include <glext.h>
#include "Extensions/ARB_multitexture_extension.h"
#include "Extensions/ARB_texture_cube_map_extension.h"
#include "Extensions/ARB_texture_env_combine_extension.h"
#include "Extensions/ARB_texture_env_dot3_extension.h"
#include "Image/IMAGE.h"
#include "Maths/Maths.h"
#include "OBJECT.h"
#include "Normalisation Cube Map.h"
#include "main.h"
class bump_map
{
public:
	int choice;
	IMAGE normalMapImagelist[3];
	IMAGE decalImagelist[3];
	IMAGE decalImage;
	IMAGE normalMapImage;

	int upi = 0, ortho = 0, ortfront = 0, ortright = 0, orttop = 0;  // Flags to set Views

	OBJECT OBJ;
	//Normal map
	GLuint normalMap;

	//Decal texture
	GLuint decalTexture;

	//Normalisation cube map
	GLuint normalisationCubeMap;

	//Light position in world space
	VECTOR3D worldLightPosition = VECTOR3D(10.0f, 10.0f, 10.0f);

	bool drawBumps = true;
	bool drawColor = true;

	//Called for initiation
	void Init(void)
	{
		OBJ.choice = choice;
		if (this->choice == 1)
		{
			normalMapImage.Load("8w.bmp");
			decalImage.Load("5w.bmp");
			OBJ.InitTri();
		}
		else if (this->choice == 2)
		{
			normalMapImage.Load("bmp3.bmp");
			decalImage.Load("1.bmp");
			OBJ.InitSQ();
		}
		else if (this->choice == 3)
		{
			normalMapImage.Load("bmp2.bmp");
			decalImage.Load("back1.bmp");
			OBJ.InitRM();
		}
		//Check for and set up extensions
		if (!SetUpARB_multitexture() || !SetUpARB_texture_cube_map() ||
			!SetUpARB_texture_env_combine() || !SetUpARB_texture_env_dot3())
		{
			printf("Required Extension Unsupported\n");
			exit(0);
		}

		//Load identity modelview
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		//Shading states
	//	glShadeModel(GL_SMOOTH);
		glClearColor(0.0f, 0.3f, 0.2f, 1.0f);
		//glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	//	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

		//Depth states
		//glClearDepth(1.0f);
		//glDepthFunc(GL_LEQUAL);
		////glEnable(GL_DEPTH_TEST);

		//glEnable(GL_CULL_FACE);
		////Load normal map
	//	IMAGE normalMapImage;
		//normalMapImage.Load("Normal map.bmp");
		normalMapImage.ExpandPalette();

		//Convert normal map to texture
		glGenTextures(1, &normalMap);
		glBindTexture(GL_TEXTURE_2D, normalMap);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, normalMapImage.width, normalMapImage.height,
			0, normalMapImage.format, GL_UNSIGNED_BYTE, normalMapImage.data);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		//Load decal image
		//IMAGE decalImage;
		//decalImage.Load("decal.bmp");
		decalImage.ExpandPalette();

		//Convert decal image to texture
		glGenTextures(1, &decalTexture);
		glBindTexture(GL_TEXTURE_2D, decalTexture);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, decalImage.width, decalImage.height,
			0, decalImage.format, GL_UNSIGNED_BYTE, decalImage.data);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);


		//Create normalisation cube map
		glGenTextures(1, &normalisationCubeMap);
		glBindTexture(GL_TEXTURE_CUBE_MAP_ARB, normalisationCubeMap);
		GenerateNormalisationCubeMap();
		glTexParameteri(GL_TEXTURE_CUBE_MAP_ARB, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_CUBE_MAP_ARB, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_CUBE_MAP_ARB, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_CUBE_MAP_ARB, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_CUBE_MAP_ARB, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
	}
	void init1()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLoadIdentity();
		glViewport(10, 10, 650, 500);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(2, 8, 2, 8);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

	}
	void init2()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLoadIdentity();
		glViewport(300, 100, 1200, 800);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(2, 8, 2, 8);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

	}
	//Called to draw scene
	void Display()
	{
		
		//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//init2();
		//glViewport(130, 100, 640, 480);
		//glMatrixMode(GL_PROJECTION);
		//glLoadIdentity();
		////{ 525, 50.0, -200.0 };  // eye/ Camera Position
		//static GLdouble object[] = { 600, 30, -300 };  // look Position
		//static GLdouble up[] = { 0.0, 1.0, 0.0 };

		//gluLookAt(viewer[0], viewer[1], viewer[2], object[0], object[1], object[2], up[0], up[1], up[2]);

		//Define Viewing Volume

		//use gluLookAt to look at OBJ
		//gluLookAt(0.0f, 10.0f, 10.0f,	0.0f, 0.0f, 0.0f,			0.0f, 1.0f, 0.0f);
//		gluLookAt(10, 10.0, -200, 0, 0, 0, 0.0, 1.0, 0.0);

		//rotate OBJ
		/*static float angle = 0.0f;
		if (choice==3)
		angle = 1.0f;
		glRotatef(angle,1.0f, 0.0f, 0.0f);
*/

		//Get the inverse model matrix
		MATRIX4X4 inverseModelMatrix;
		glPushMatrix();
		glLoadIdentity();
	//glRotatef(-angle, 0.0f, 1.0f, 0.0f);
		glGetFloatv(GL_MODELVIEW_MATRIX, inverseModelMatrix);
		glPopMatrix();

		//Get the OBJ space light vector
		VECTOR3D objectLightPosition = inverseModelMatrix*worldLightPosition;

		//Loop through vertices
		for (int i = 0; i<OBJ.numVertices; ++i)
		{
			VECTOR3D lightVector = objectLightPosition - OBJ.vertices[i].position;

			//Calculate tangent space light vector
			OBJ.vertices[i].tangentSpaceLight.x =
				OBJ.vertices[i].sTangent.DotProduct(lightVector);
			OBJ.vertices[i].tangentSpaceLight.y =
				OBJ.vertices[i].tTangent.DotProduct(lightVector);
			OBJ.vertices[i].tangentSpaceLight.z =
				OBJ.vertices[i].normal.DotProduct(lightVector);
		}


		//Draw bump pass
		if (drawBumps)
		{
			//Bind normal map to texture unit 0
			glBindTexture(GL_TEXTURE_2D, normalMap);
			glEnable(GL_TEXTURE_2D);

			//Bind normalisation cube map to texture unit 1
			glActiveTextureARB(GL_TEXTURE1_ARB);
			glBindTexture(GL_TEXTURE_CUBE_MAP_ARB, normalisationCubeMap);
			glEnable(GL_TEXTURE_CUBE_MAP_ARB);
			glActiveTextureARB(GL_TEXTURE0_ARB);

			//Set vertex arrays for OBJ
			glVertexPointer(3, GL_FLOAT, sizeof(VERTEX), &OBJ.vertices[0].position);
			glEnableClientState(GL_VERTEX_ARRAY);

			//Send texture coords for normal map to unit 0
			glTexCoordPointer(2, GL_FLOAT, sizeof(VERTEX), &OBJ.vertices[0].s);
			glEnableClientState(GL_TEXTURE_COORD_ARRAY);

			//Send tangent space light vectors for normalisation to unit 1
			glClientActiveTextureARB(GL_TEXTURE1_ARB);
			glTexCoordPointer(3, GL_FLOAT, sizeof(VERTEX), &OBJ.vertices[0].tangentSpaceLight);
			glEnableClientState(GL_TEXTURE_COORD_ARRAY);
			glClientActiveTextureARB(GL_TEXTURE0_ARB);


			//Set up texture environment to do (tex0 dot tex1)*color
			glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_COMBINE_ARB);
			glTexEnvi(GL_TEXTURE_ENV, GL_SOURCE0_RGB_ARB, GL_TEXTURE);
			glTexEnvi(GL_TEXTURE_ENV, GL_COMBINE_RGB_ARB, GL_REPLACE);

			glActiveTextureARB(GL_TEXTURE1_ARB);

			glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_COMBINE_ARB);
			glTexEnvi(GL_TEXTURE_ENV, GL_SOURCE0_RGB_ARB, GL_TEXTURE);
			glTexEnvi(GL_TEXTURE_ENV, GL_COMBINE_RGB_ARB, GL_DOT3_RGB_ARB);
			glTexEnvi(GL_TEXTURE_ENV, GL_SOURCE1_RGB_ARB, GL_PREVIOUS_ARB);

			glActiveTextureARB(GL_TEXTURE0_ARB);



			//Draw OBJ
			glDrawElements(GL_TRIANGLES, OBJ.numIndices, GL_UNSIGNED_INT, OBJ.indices);


			//Disable textures
			glDisable(GL_TEXTURE_2D);

			glActiveTextureARB(GL_TEXTURE1_ARB);
			glDisable(GL_TEXTURE_CUBE_MAP_ARB);
			glActiveTextureARB(GL_TEXTURE0_ARB);

			//disable vertex arrays
			glDisableClientState(GL_VERTEX_ARRAY);

			glDisableClientState(GL_TEXTURE_COORD_ARRAY);

			glClientActiveTextureARB(GL_TEXTURE1_ARB);
			glDisableClientState(GL_TEXTURE_COORD_ARRAY);
			glClientActiveTextureARB(GL_TEXTURE0_ARB);

			//Return to standard modulate texenv
			glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
		}

		//If we are drawing both passes, enable blending to multiply them together
		if (drawBumps && drawColor)
		{
			//Enable multiplicative blending
			glBlendFunc(GL_DST_COLOR, GL_ZERO);
			glEnable(GL_BLEND);
		}

		//Perform a second pass to color the OBJ
		if (drawColor)
		{
			if (!drawBumps)
			{
				glLightfv(GL_LIGHT1, GL_POSITION, VECTOR4D(objectLightPosition));
				glLightfv(GL_LIGHT1, GL_DIFFUSE, white);
				glLightfv(GL_LIGHT1, GL_AMBIENT, black);
				glLightModelfv(GL_LIGHT_MODEL_AMBIENT, black);
				glEnable(GL_LIGHT1);
				glEnable(GL_LIGHTING);

				glMaterialfv(GL_FRONT, GL_DIFFUSE, white);
			}

			//Bind decal texture
			glBindTexture(GL_TEXTURE_2D, decalTexture);
			glEnable(GL_TEXTURE_2D);

			//Set vertex arrays for OBJ
			glVertexPointer(3, GL_FLOAT, sizeof(VERTEX), &OBJ.vertices[0].position);
			glEnableClientState(GL_VERTEX_ARRAY);

			glNormalPointer(GL_FLOAT, sizeof(VERTEX), &OBJ.vertices[0].normal);
			glEnableClientState(GL_NORMAL_ARRAY);

			glTexCoordPointer(2, GL_FLOAT, sizeof(VERTEX), &OBJ.vertices[0].s);
			glEnableClientState(GL_TEXTURE_COORD_ARRAY);

			//Draw OBJ
			glDrawElements(GL_TRIANGLES, OBJ.numIndices, GL_UNSIGNED_INT, OBJ.indices);

			if (!drawBumps)
				glDisable(GL_LIGHTING);

			//Disable texture
			glDisable(GL_TEXTURE_2D);

			//disable vertex arrays
			glDisableClientState(GL_VERTEX_ARRAY);
			glDisableClientState(GL_NORMAL_ARRAY);
			glDisableClientState(GL_TEXTURE_COORD_ARRAY);
		}

		//Disable blending if it is enabled
		if (drawBumps && drawColor)
			glDisable(GL_BLEND);

		glFinish();
		glutSwapBuffers();
		glutPostRedisplay();

	}
};