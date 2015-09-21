#include "AppClass.h"
void AppClass::InitWindow(String a_sWindowName)
{
	//Using Base InitWindow method
	super::InitWindow("LASTNAME, FIRSTNAME - 3D Transformations");
}

void AppClass::InitVariables(void)
{
	m_pSphere = new PrimitiveClass();

	//Initializing the primitives
	m_pSphere->GenerateSphere(1.0f, 5, REWHITE);
}

void AppClass::Update(void)
{
	m_m4Sphere = glm::translate(matrix4(IDENTITY), vector3(2.5f, 2.5f, 0.0f));

	//First person camera movement
	if (m_bFPC == true)
		CameraRotation();
}

void AppClass::Display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clear the window

	m_pGrid->Render(0.10f, REAXIS::XY); //renders the grid with a 100 scale

	//Renders the meshes using the specified position given by the matrix and in the specified color
	m_pSphere->Render(m_m4Sphere);

	m_pGLSystem->GLSwapBuffers(); //Swaps the OpenGL buffers
}

void AppClass::Release(void)
{
	SafeDelete(m_pSphere);
	
	super::Release();
}