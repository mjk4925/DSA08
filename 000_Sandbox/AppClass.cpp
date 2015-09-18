#include "AppClass.h"
void AppClass::InitApplication(void)
{
	//Using Base InitApplication method
	super::InitApplication();

	//Rename application's window
	m_pSystem->WindowName = "Sandbox";
}

void AppClass::InitUserVariables(void)
{
	//Changing the clear color
	m_v4ClearColor = vector4(0.0f);

	//There is a default grid created for the XZ plane, I want it on the XY so I recreate it.
	SafeDelete(m_pGrid);
	// Create a new grid initializing its properties and compiling it
	m_pGrid = new GridClass(MEAXIS::XY);
	m_pGrid->CompileGrid();
}

void AppClass::Update(void)
{
	//Update the system so it knows how much time has passed since the last call
	m_pSystem->UpdateTime();

	//Update the information on the Mesh manager I will not check for collision detection so the argument is false
	m_pMeshMngr->Update(false);

	//Is the arcball active?
	if (m_bArcBall == true)
		m_m4ArcBall = ArcBall();

	//Is the first person camera active?
	if (m_bFPC == true)
		CameraRotation();

	//Calculate new camera position
	m_pCamera->CalculateView();

	//print info into the console
	printf("FPS: %d            \r", m_pSystem->GetFPS()); //print the Frames per Second
}

void AppClass::Display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear the window

	m_pGrid->Render(100.0f); // Renders the grid with at a 100 scale

	m_pMeshMngr->Render(); // Will render all the objects in the Render List

	m_pGLSystem->GLSwapBuffers(); // Swaps the OpenGL buffers
}

void AppClass::Release(void)
{
	super::Release(); // Releasing the base class's fields
}