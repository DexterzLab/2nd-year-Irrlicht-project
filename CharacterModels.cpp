#include "CharacterModels.h"



CharacterModels::CharacterModels()
{
}


CharacterModels::~CharacterModels()
{
}


IAnimatedMeshSceneNode * CharacterModels::createCharacter(
	const char *model_filename,
	const char *texture_filename,
	vector3df pos,
	vector3df rotation,
	vector3df scale,
	ISceneManager *scnmgr,
	IVideoDriver *driver)
{
	//load model from file
	IAnimatedMesh *mesh = scnmgr->getMesh(model_filename);

	//check the mesh was loaded okay
	if (mesh == nullptr) {
		return nullptr;
	}

	//Create scene node for mesh 
	IAnimatedMeshSceneNode *scene_node = scnmgr->addAnimatedMeshSceneNode(mesh);

	//Set up the animated mesh scene node
	scene_node->setMaterialFlag(EMF_LIGHTING, false);
	scene_node->setMaterialTexture(0, driver->getTexture(texture_filename));
	scene_node->setPosition(pos);
	scene_node->setRotation(rotation);
	scene_node->setScale(scale);

	return scene_node;


}