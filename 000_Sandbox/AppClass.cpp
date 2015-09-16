#include "AppClass.h"
void AppClass::InitUserVariables(void)
{
	SafeDelete(m_pGrid);
	// Create a new grid initializing its properties and compiling it
	m_pGrid = new GridClass(MEAXIS::XY);
	m_pGrid->CompileGrid();
}

void AppClass::Update(void)
{
	//First person camera movement
	if (m_bFPC == true)
		CameraRotation();
}

void AppClass::Display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clear the window

	m_pGrid->Render(10.0f); //renders the grid with a 100 scale

	m_pGLSystem->GLSwapBuffers(); //Swaps the OpenGL buffers
}

void AppClass::Release(void)
{
	super::Release();
}