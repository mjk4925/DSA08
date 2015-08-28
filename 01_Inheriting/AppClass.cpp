#include "AppClass.h"
void AppClass::InitApplication(void)
{
	//Using Base InitApplication method
	super::InitApplication();
	//Renaming the application
	m_pSystem->WindowName = "Inheriting (No keyboard control, close with Alt + F4)";
	//Changing the clear color
	m_v4ClearColor = vector4(0.0f);
}

void AppClass::InitUserVariables(void)
{
	//Enable ArcBall
	m_bArcBall = true;
	//Enable FPC
	//m_bFPC = true;
}