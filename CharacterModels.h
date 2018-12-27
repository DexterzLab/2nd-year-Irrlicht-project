
//[1] Add the Irrlicht include header 

#include <irrlicht.h>

//[2] Add the appropriate namespaces

using namespace irr;
using namespace core;
using namespace video;
using namespace scene;


//[3] Add the #pragma directive to add the irrlicht.lib file
#pragma comment (lib, "irrlicht.lib")


class CharacterModels
{
public:


	IAnimatedMeshSceneNode * createCharacter(
		const char *model_filename,
		const char *texture_filename,
		vector3df pos,
		vector3df rotation,
		vector3df scale,
		ISceneManager *scnmgr,
		IVideoDriver *driver);

	
	CharacterModels();
	~CharacterModels();
};

