 //Irrlicht  header 

#include <irrlicht.h>

//namespaces

using namespace irr;
using namespace core;
using namespace video;
using namespace scene;


//Adding the irrlicht.lib file
#pragma comment (lib, "irrlicht.lib")


class StaticModels
{
public:

	IMeshSceneNode * createModel(
		const char *model_filename,
		const char *texture_filename,
		vector3df pos,
		vector3df rotation,
		vector3df scale,
		ISceneManager *scnmgr,
		IVideoDriver *driver);




	StaticModels();
	~StaticModels();
};

