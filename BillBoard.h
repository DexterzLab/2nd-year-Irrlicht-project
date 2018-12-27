#include <irrlicht.h>

//namespaces

using namespace irr;
using namespace core;
using namespace video;
using namespace scene;

#pragma comment (lib, "irrlicht.lib")

class BillBoard
{
public:
	BillBoard();
	~BillBoard();
	

	//Function for creating a billboard
	IBillboardSceneNode * createBillboard(
		const char * billboard_filename, 
		ISceneNode * node,
		dimension2d<f32> size,
		vector3df  position,
		ISceneManager * scnmgr, 
		IVideoDriver * driver);
};

