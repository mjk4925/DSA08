#include "AppClass.h"
void AppClass::InitApplication(void)
{
	//Using Base InitApplication method
	super::InitApplication();
	//Renaming the application
	m_pSystem->WindowName = "3D Shapes";
}

void AppClass::InitUserVariables(void)
{
	//The grid is defined for XZ by default, so I will destroy it and
	//recreate it for the XY plane or I could also just rotate it.
	SafeDelete(m_pGrid);
	m_pGrid = new GridClass(MEAXIS::XY);
	m_pGrid->CompileGrid();

	//Setting the camera into the right position
	m_pCamera->SetPosition(vector3(0.0f, 0.0f, 10.0f));

	//Reserve Memory for a MyMeshClass object
	m_pMesh = new MyPrimitive();
	m_pMesh->GenerateCube(1.0f, MEWHITE);
	//m_pMesh->GenerateCone(3.0f, 1.0f, 10, MERED);
}

void AppClass::Update(void)
{
	//Update the system so it knows how much time has passed since the last call
	m_pSystem->UpdateTime();

	//Is the arcball active?
	if (m_bArcBall == true)
		m_m4ArcBall = ArcBall();

	//Is the first person camera active?
	if (m_bFPC == true)
		CameraRotation();

	//Calculate Camera
	m_pCamera->CalculateView();

	//print info into the console
	printf("FPS: %d            \r", m_pSystem->GetFPS());//print the Frames per Second
}

void AppClass::Display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clear the window

	m_pGrid->Render(100.0f); //renders the grid with a 100 scale

	m_pMesh->Render(m_m4ArcBall);//Rendering nObjects

	m_pGLSystem->GLSwapBuffers(); //Swaps the OpenGL buffers
}

void AppClass::Release(void)
{
	if (m_pMesh != nullptr)
	{
		delete m_pMesh;
		m_pMesh = nullptr;
	}
	super::Release();
}