#include "AppClass.h"
void AppClass::InitApplication(void)
{
	//Using Base InitApplication method
	super::InitApplication();
	//Renaming the application
	m_pSystem->WindowName = "LASTNAME, FIRSTNAME - 3D Transformations";
}

void AppClass::InitUserVariables(void)
{
	SafeDelete(m_pGrid);
	// Create a new grid initializing its properties and compiling it
	m_pGrid = new GridClass(MEAXIS::XY);
	m_pGrid->CompileGrid();

	m_pSphere = new PrimitiveClass();

	//Initializing the primitives
	m_pSphere->GenerateSphere(1.0f, 5, MEWHITE);
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

	m_pGrid->Render(10.0f); //renders the grid with a 100 scale

	//Renders the meshes using the specified position given by the matrix and in the specified color
	m_pSphere->Render(m_m4Sphere);

	m_pGLSystem->GLSwapBuffers(); //Swaps the OpenGL buffers
}

void AppClass::Release(void)
{
	SafeDelete(m_pSphere);
	
	super::Release();
}