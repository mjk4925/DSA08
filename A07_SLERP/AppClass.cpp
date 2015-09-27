#include "AppClass.h"
void AppClass::InitWindow(String a_sWindowName)
{
	super::InitWindow("A07 - SLERP"); // Window Name

	//Setting the color to black
	m_v4ClearColor = vector4(0.0f);
}
void AppClass::InitVariables(void)
{
	//Setting the position in which the camera is looking and its interest point
	m_pCamera->SetPositionAndView(vector3(12.12f, 28.52f, 11.34f), vector3(0.0f));

	//Setting the color to black
	m_v4ClearColor = vector4(0.0f);

	//Loading the models
	m_pMeshMngr->LoadModel("Planets\\00_Sun.obj", "Sun");
	m_pMeshMngr->LoadModel("Planets\\03_Earth.obj", "Earth");
	m_pMeshMngr->LoadModel("Planets\\03A_Moon.obj", "Moon");

	//Setting the days duration
	m_fDay = 1.0f;
}

void AppClass::Update(void)
{
	//Update the system's time
	m_pSystem->UpdateTime();

	//Update the mesh manager's time without updating for collision detection
	m_pMeshMngr->Update(false);

	//First person camera movement
	if (m_bFPC == true)
		CameraRotation();

	//Getting the time between calls
	float fCallTime = m_pSystem->LapClock();
	//Counting the cumulative time
	static float fRunTime = 0.0f;
	fRunTime += fCallTime;

	//Earth Orbit
	static int nEarthOrbits = 0; //count the number of orbits
		
	//Earth Revolution
	static int nEarthRevolutions = 0;
	
	//Moon Orbit
	static int nMoonOrbits = 0;

	//Adds all loaded instance to the render list
	m_pMeshMngr->AddInstanceToRenderList("ALL");

	printf("\rTime:%.2f[s] Day:%.2f[s] E_Orbits:%d E_Revolutions:%d M_Orbits:%d         ", fRunTime, m_fDay, nEarthOrbits, nEarthRevolutions, nMoonOrbits);
}

void AppClass::Display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clear the window

	m_pMeshMngr->Render(); //renders the render list

	m_pGLSystem->GLSwapBuffers(); //Swaps the OpenGL buffers
}

void AppClass::Release(void)
{
	super::Release(); //release the memory of the inherited fields
}
