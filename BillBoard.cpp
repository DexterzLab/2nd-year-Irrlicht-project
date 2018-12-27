#include "BillBoard.h"



BillBoard::BillBoard()
{
}


BillBoard::~BillBoard()
{
}

/*The driver will search for the filepath in the first parameter
and then the function will run a normal billboard function
taking in the rest of the parameters such as node, size and position.
*/
IBillboardSceneNode * BillBoard::createBillboard(
	const char *billboard_filename,
	ISceneNode *node,
	dimension2d<f32> size,
	vector3df position,
	ISceneManager *scnmgr,
	IVideoDriver *driver) {

	IBillboardSceneNode *billboard = scnmgr->addBillboardSceneNode(node,size,position);

	billboard->setMaterialFlag(EMF_LIGHTING, false);
	billboard->setMaterialTexture(0, driver->getTexture(billboard_filename));
	billboard->setMaterialType(EMT_TRANSPARENT_ALPHA_CHANNEL);

	return billboard;
}