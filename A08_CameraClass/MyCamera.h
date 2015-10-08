/////////////////////////////////////////////////////////////////////
// File: MyCamera.h
// DSA2 A08_CameraClass
// Authors:
// 
// Singleton Camera Class
/////////////////////////////////////////////////////////////////////

#ifndef _MYCAMERA_H_
#define _MYCAMERA_H_

#include "RE\ReEngAppClass.h"

class MyCamera
{
private:
	static MyCamera* inst;  //Singleton Camera Instance

	/////////////////////////////////////////////////////////////////
	// MyCamera() - Private Singleton constructor
	/////////////////////////////////////////////////////////////////
	MyCamera();             

public:
	/////////////////////////////////////////////////////////////////
	// GetInstance() - return the singleton inst of camera
	/////////////////////////////////////////////////////////////////
	static MyCamera* GetInstance();

	/////////////////////////////////////////////////////////////////
	// ReleaseInst() - Release the camera singleton instance
	/////////////////////////////////////////////////////////////////
	static void ReleaseInst();

	/////////////////////////////////////////////////////////////////
	// GetView() - return the camera view matrix
	/////////////////////////////////////////////////////////////////
	matrix4 GetView();

	/////////////////////////////////////////////////////////////////
	// GetProjection() - return the projection matrix 
	//
	// @param 
	//   bOrthographic - (0=Perspective, 1=Orthographic)
	/////////////////////////////////////////////////////////////////
	matrix4 GetProjection(bool bOrthographic);

	/////////////////////////////////////////////////////////////////
	// SetPosition() - Sets the position of the camera
	//
	// @param 
	//   v3Position - new camera position
	/////////////////////////////////////////////////////////////////
	void SetPosition(vector3 v3Position);

	/////////////////////////////////////////////////////////////////
	// SetTarget() - Sets the target of the camera
	//
	// @param 
	//   v3Target - new camera target
	/////////////////////////////////////////////////////////////////
	void SetTarget(vector3 v3Target);

	/////////////////////////////////////////////////////////////////
	// SetUp() - Sets the up vector of the camera
	//
	// @param 
	//   v3Up - new camera up vector
	/////////////////////////////////////////////////////////////////
	void SetUp(vector3 v3Up);

	/////////////////////////////////////////////////////////////////
	// MoveForward() - move the camera forward/back 
	//                 (depending on view vector)
	// @param 
	//   fIncrement - 
	/////////////////////////////////////////////////////////////////
	void MoveForward(float fIncrement);

	/////////////////////////////////////////////////////////////////
	// MoveSideways() - move camera right/left
	//                 (depending on view vector)
	// @param 
	//   fIncrement - 
	/////////////////////////////////////////////////////////////////
	void MoveSideways(float fIncrement);

	/////////////////////////////////////////////////////////////////
	// MoveVertical() - move camera up/down
	//                 (depending on up vector)
	// @param 
	//   fIncrement - 
	/////////////////////////////////////////////////////////////////
	void MoveVertical(float fIncrement);

	/////////////////////////////////////////////////////////////////
	// ChangePitch() - Orient camera changing its angle in x
	//                 
	// @param 
	//   fIncrement - 
	/////////////////////////////////////////////////////////////////
	void ChangePitch(float fIncrement);

	/////////////////////////////////////////////////////////////////
	// ChangeRoll() - Orient camera changing its angle in z
	//                 
	// @param 
	//   fIncrement - 
	/////////////////////////////////////////////////////////////////
	void ChangeRoll(float fIncrement);

	/////////////////////////////////////////////////////////////////
	// ChangeYaw() - Orient camera changing its angle in y
	//                 
	// @param 
	//   fIncrement - 
	/////////////////////////////////////////////////////////////////
	void ChangeYaw(float fIncrement);
};










#endif /*_MYCAMERA_H_*/