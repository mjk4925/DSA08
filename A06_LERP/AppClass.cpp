#include "AppClass.h"
void AppClass::InitWindow(String a_sWindowName)
{
	super::InitWindow("Assignment  06 - LERP"); //Base's InitWindow
}

void AppClass::InitVariables(void)
{
	//Sets the camera
	m_pCamera->SetPositionAndView(vector3(0.0f, 0.0f, 15.0f), vector3(0.0f)); //DOES NOT NEED CHANGES

	// Color of the screen
	m_v4ClearColor = vector4(REBLACK,1);//DOES NOT NEED CHANGES

	//Loads the character
	m_pMeshMngr->LoadModel("Sorted\\WallEye.obj", "WallEye");//DOES NOT NEED CHANGES

}

void AppClass::Update(void)
{
	//Update the system clock
	m_pSystem->UpdateTime();//DOES NOT NEED CHANGES

	//Update the Mesh Manager
	m_pMeshMngr->Update(false);//DOES NOT NEED CHANGES

	//Lets us know how much time has passed since the last call
	float fTimeSpan = m_pSystem->LapClock();//DOES NOT NEED CHANGES

	//cumulative time
	static float fRunTime = 0.0f;//DOES NOT NEED CHANGES
	fRunTime += fTimeSpan;//DOES NOT NEED CHANGES

	//example
	m_pMeshMngr->SetModelMatrix(glm::translate(vector3(0.0f)), "WallEye");
	m_pMeshMngr->AddSphereToQueue(glm::translate(vector3(1.0f)) * glm::scale(vector3(0.1f)), RERED, SOLID);
	printf("\rfTimeSpan: %.3f, fRunSpan: %.3f, fDuration: %.3f                 ", fTimeSpan, fRunTime, fDuration);

	//Adds all instances to the render list
	m_pMeshMngr->AddInstanceToRenderList("ALL");//DOES NOT NEED CHANGES
}

void AppClass::Release(void)
{
	super::Release();//DOES NOT NEED CHANGES unless you reserved new memory
}