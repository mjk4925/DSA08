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
	//The grid is defined for XZ by default, so I will destroy it and
	//recreate it for the XY plane or I could also just rotate it.
	SafeDelete(m_pGrid);
	m_pGrid = new GridClass(MEAXIS::XZ);
	m_pGrid->CompileGrid();

	// Set the camera into the initial position
	m_pCamera->SetUpVector(vector3(0.0f, 0.0f, -1.0f));
	m_pCamera->SetPositionAndView(vector3(0.0f, 25.0f, 0.0f), vector3(0.0f, 0.0f, 0.0f));

	//Starting the values of the transformation matricies to the identity (defined under MEDEFINIONS.h)
	m_m4Sun = matrix4(IDENTITY); 
	m_m4Earth = matrix4(IDENTITY);
	m_m4Moon = matrix4(IDENTITY);

	//Starting the new primitive objects as PrimitiveClass objects (like MyPrimitive but inside ReEng.dll)
	m_pSun = new PrimitiveClass();
	m_pEarth = new PrimitiveClass();
	m_pMoon = new PrimitiveClass();

	//Initializing the primitives
	m_pSun->GenerateSphere(5.936f, 5, MEYELLOW);
	m_pEarth->GenerateTube(0.524f, 0.45f, 0.3f, 10, MEBLUE);
	m_pMoon->GenerateTube(0.524f * 0.27f, 0.45f * 0.27f, 0.3f * 0.27f, 10, MEWHITE);
}

void AppClass::Update(void)
{
	//This matrices will just orient the objects to the camera (which is looking from
	matrix4 rotateX = glm::rotate(matrix4(IDENTITY), 90.0f, vector3(1.0f, 0.0f, 0.0f));
	matrix4 rotateY = glm::rotate(matrix4(IDENTITY), 90.0f, vector3(0.0f, 1.0f, 0.0f));

	//First person camera movement
	if (m_bFPC == true)
		CameraRotation();

	printf("Earth Day: %.3f, Moon Day: %.3f\r", m_fEarthTimer, m_fMoonTimer);//print the Frames per Second
}

void AppClass::Display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clear the window

	m_pGrid->Render(100.0f); //renders the grid with a 100 scale

	//Renders the meshes using the specified position given by the matrix and in the specified color
	m_pSun->Render(m_m4Sun);
	m_pEarth->Render(m_m4Earth);
	m_pMoon->Render(m_m4Moon);

	m_pGLSystem->GLSwapBuffers(); //Swaps the OpenGL buffers
}

void AppClass::Release(void)
{
	SafeDelete(m_pEarth);
	SafeDelete(m_pMoon);
	SafeDelete(m_pSun);
	
	super::Release();
}