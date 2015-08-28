#include "AppClass.h"
void AppClass::InitApplication(void)
{
	//Using Base InitApplication method
	super::InitApplication();
	//Renaming the application
	m_pSystem->WindowName = "SFML CONTROLS (Esc to terminate)";
}

void AppClass::InitUserVariables(void)
{
	//Load a model into memory
	m_pMeshMngr->LoadModelUnthreaded("Minecraft\\MC_Steve.obj", "Steve");
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

	//Modify model's ModelToWorld matrix
	m_pMeshMngr->SetModelMatrix(m_m4ArcBall, "Steve");

	//Add a model to the render list
	m_pMeshMngr->AddInstanceToRenderList("Steve");

	//Calculate Camera
	m_pCamera->CalculateView();

	//print info into the console
	printf("FPS: %d            \r", m_pSystem->GetFPS());//print the Frames per Second
}