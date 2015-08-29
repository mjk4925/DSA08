#include "AppClass.h"
void AppClass::InitApplication(void)
{
	//Using Base InitApplication method
	super::InitApplication();
	//Renaming the application
	m_pSystem->WindowName = "Instance Rendering - Example";
}

void AppClass::InitUserVariables(void)
{
	//Reserve Memory for a MyMeshClass object
	m_pMesh = new MyMesh();

	m_pMesh->AddVertexPosition(vector3(0.0f, 0.0f, 0.0f));
	m_pMesh->AddVertexPosition(vector3(5.0f, 0.0f, 0.0f));
	m_pMesh->AddVertexPosition(vector3(0.0f, 5.0f, 0.0f));

	m_pMesh->AddVertexColor(MEGREEN);
	m_pMesh->AddVertexColor(MERED);
	m_pMesh->AddVertexColor(MEBLUE);
	
	m_pMesh->CompileOpenGL3X();

	m_fMatrixArray = new float[m_nObjects * 16];
	for (int nObject = 0; nObject < m_nObjects; nObject++)
	{
		const float* m4MVP = glm::value_ptr(
			glm::translate(vector3(0.01f * -nObject, 0.0f, 1.0f * -nObject)) *
			glm::rotate(MEIDENTITY, nObject * 5.0f, MEAXISZ)
			);
		memcpy(&m_fMatrixArray[nObject * 16], m4MVP, 16 * sizeof(float));
	}
	
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

	m_pMesh->RenderList(m_fMatrixArray, m_nObjects);//Rendering nObjects

	m_pGLSystem->GLSwapBuffers(); //Swaps the OpenGL buffers
}

void AppClass::Release(void)
{
	SafeDelete(m_fMatrixArray);
	if (m_pMesh != nullptr)
	{
		delete m_pMesh;
		m_pMesh = nullptr;
	}
	super::Release();
}