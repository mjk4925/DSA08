/*----------------------------------------------
Programmer: Alberto Bobadilla (labigm@gmail.com)
Date: 2015/06
----------------------------------------------*/
#ifndef __GRIDCLASS_H_
#define __GRIDCLASS_H_

#include "RE\Mesh\MeshClass.h"

namespace ReEng
{

class ReEngDLL GridClass : public MeshClass
{
	typedef MeshClass super;

public:
	//Constructor
	GridClass(int a_Axis = MEAXIS::XY | MEAXIS::XZ | MEAXIS::YZ, float a_fSpacing = 100.0f);
	//Copy Constructor
	GridClass(const GridClass& other);
	//Copy Assignment Operator
	virtual GridClass& operator=(const GridClass& other);

	//Destructor
	~GridClass(void);
		
	//Renders the content of the shape
	virtual void Render(float a_fSize = 100.0f);

	void CompileGrid(void);
};

EXPIMP_TEMPLATE template class ReEngDLL std::vector<GridClass>;
EXPIMP_TEMPLATE template class ReEngDLL std::vector<GridClass*>;

}
#endif //GRIDCLASS