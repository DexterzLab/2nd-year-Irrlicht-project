#include "StaticModels.h"



StaticModels::StaticModels()
{
}


StaticModels::~StaticModels()
{
}

IMeshSceneNode * StaticModels::createModel(
	const char *model_filename,
	const char *texture_filename,
	vector3df pos,
	vector3df rotation,
	vector3df scale,
	ISceneManager *scnmgr,
	IVideoDriver *driver)
{
	//load model from file
	IMesh *mesh = scnmgr->getMesh(model_filename);

	//check the mesh was loaded okay
	if (mesh == nullptr) {
		return nullptr;
	}

	//Create scene node for mesh 
	IMeshSceneNode *scene_node = scnmgr->addMeshSceneNode(mesh);

	//Set up the animated mesh scene node
	scene_node->setMaterialFlag(EMF_LIGHTING, false);
	scene_node->setMaterialTexture(0, driver->getTexture(texture_filename));
	scene_node->setPosition(pos);
	scene_node->setRotation(rotation);
	scene_node->setScale(scale);

	return scene_node;


}



