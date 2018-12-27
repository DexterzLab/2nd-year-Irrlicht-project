#include "GameScene.h"
#include "CharacterModels.h"
#include "StaticModels.h"
#include "KeyReceiver.h"
#include "BillBoard.h"
//The Irrlicht include header 
#include <irrlicht.h>
//The irrklang include header
#include<irrklang.h>
#include <iostream>

//The appropriate namespaces

using namespace irr;
using namespace core;
using namespace video;
using namespace scene;
using namespace gui;
using namespace irrklang;


//The #pragma directive to add the irrlicht.lib file and irrklang.lib file
#pragma comment (lib, "irrklang.lib ")
#pragma comment (lib, "irrlicht.lib")





int main(void)
{


	//Create an object of the KeyReceiver class to pass to the createDevice function
	// This gives Irrlicht a destination to send events to.  As a side exercise find out if Irrlicht only sends keyboard events or all events such as from the mouse.

	KeyReceiver ker;


	// Create the Irrlicht device and set the video type to EDT_SOFTWARE
	IrrlichtDevice *device = createDevice(EDT_DIRECT3D9, dimension2d<u32>(1024, 768), 16, false, false, false, &ker);
	// Check if the video device exists otherwise exit.

	// Check device object was created successfully
	if (device == nullptr) {
		return 0;
	}

	// Obtain the video driver object from the Irrlicht device
	IVideoDriver *driver = device->getVideoDriver();
	// Obtain the scene manager object from the Irrlicht device
	ISceneManager *scnmgr = device->getSceneManager();
	//Get the driver from the irrklnag plugin
	ISoundEngine *engine = createIrrKlangDevice();
	ISound *sound = engine->play2D("../resources/sound/Frontend.mp3", true, true);







	//STATIC MESHES FOR THE SCENE
	StaticModels Stairs[3];
	StaticModels Buildings[9];
	StaticModels Crash;
	StaticModels Phonebooth;
	StaticModels StadiumLights;
	StaticModels Streetlights;
	StaticModels Basketball;
	StaticModels Court;
	StaticModels Car;
	StaticModels Hoop;
	StaticModels ScoreBoard;
	StaticModels Judgetable;


	//10 DIFFERENT BUILDINGS
	//THESE BUILDINGS ARE NOT TO SCALE AND HAVE BEEN COLOUR CODED TO RESEMBLE THEIR THEME 
	Buildings[0].createModel("../resources/buildings/stadium.obj", NULL, vector3df(0.0f, 0.0f, 0.0f), vector3df(0.0f, 180.0f, 0.0f), vector3df(0.5f, 0.5f, 0.5f), scnmgr, driver);
	Buildings[1].createModel("../resources/buildings/cornershop.obj", NULL, vector3df(-10000.0f, 0.0f, -10000.0f), vector3df(0.0f, 90.0f, 0.0f), vector3df(0.5f, 0.5f, 0.5f), scnmgr, driver);
	Buildings[2].createModel("../resources/buildings/hotel.obj", NULL, vector3df(-10000.0f, 0.0f, -2000.0f), vector3df(0.0f, 180.0f, 0.0f), vector3df(0.5f, 0.5f, 0.5f), scnmgr, driver);
	Buildings[3].createModel("../resources/buildings/skyscraper.obj", NULL, vector3df(40000.0f, 1000.0f, 7000.0f), vector3df(0.0f, 180.0f, 0.0f), vector3df(0.5f, 0.5f, 0.5f), scnmgr, driver);
	Buildings[4].createModel("../resources/buildings/house.obj", NULL, vector3df(-10000.0f, 0.0f, -5000.0f), vector3df(0.0f, 90.0f, 0.0f), vector3df(0.5f, 0.5f, 0.5f), scnmgr, driver);
	Buildings[5].createModel("../resources/buildings/coffeeshop.obj", NULL, vector3df(-10000.0f, 0.0f, -7000.0f), vector3df(0.0f, 90.0f, 0.0f), vector3df(0.5f, 0.5f, 0.5f), scnmgr, driver);
	Buildings[6].createModel("../resources/buildings/factory.obj", NULL, vector3df(-30000.0f, 0.0f, -10000.0f), vector3df(0.0f, 90.0f, 0.0f), vector3df(0.5f, 0.5f, 0.5f), scnmgr, driver);
	Buildings[7].createModel("../resources/buildings/postoffice.obj", NULL, vector3df(-10000.0f, 0.0f, -12000.0f), vector3df(0.0f, 90.0f, 0.0f), vector3df(0.5f, 0.5f, 0.5f), scnmgr, driver);
	Buildings[8].createModel("../resources/buildings/shopping centre.obj", NULL, vector3df(10000.0f, 0.0f, 20000.0f), vector3df(0.0f, 90.0f, 0.0f), vector3df(0.5f, 0.5f, 0.5f), scnmgr, driver);
	Buildings[9].createModel("../resources/buildings/flats.obj", NULL, vector3df(-12000.0f, 0.0f, -2000.0f), vector3df(0.0f, 90.0f, 0.0f), vector3df(0.5f, 0.5f, 0.5f), scnmgr, driver);


	//10 STATIC MODELS
	Car.createModel("../resources/staticmodels/car.obj", NULL, vector3df(8000.0f, 0.0f, 500.0f), vector3df(0.0f, 0.0f, 0.0f), vector3df(0.5f, 0.5f, 0.5f), scnmgr, driver);
	Basketball.createModel("../resources/staticmodels/Ball.obj", "../resources/basketball_texture.jpg", vector3df(0.0f, 0.0f, 500.0f), vector3df(0.5f, 0.5f, 0.5f), vector3df(1.0f, 1.0f, 1.0f), scnmgr, driver);
	Court.createModel("../resources/Court.obj", "../resources/basketball_court.jpg", vector3df(0.0f, 0.0f, 0.0f), vector3df(0.0f, 0.0f, 0.0f), vector3df(0.5f, 0.5f, 0.5f), scnmgr, driver);
	Hoop.createModel("../resources/staticmodels/Hoop.obj", NULL, vector3df(0.0f, 0.0f, 1500.0f), vector3df(0.0f, 0.0f, 0.0f), vector3df(0.5f, 0.5f, 0.5f), scnmgr, driver);
	Streetlights.createModel("../resources/staticmodels/streetlights.obj", NULL, vector3df(10000.0f, 0.0f, 500.0f), vector3df(0.0f, 0.0f, 0.0f), vector3df(0.5f, 0.5f, 0.5f), scnmgr, driver);
	StadiumLights.createModel("../resources/staticmodels/stadiumlights.obj", NULL, vector3df(0.0f, 0.0f, 0.0f), vector3df(0.0f, 0.0f, 0.0f), vector3df(0.5f, 0.5f, 0.5f), scnmgr, driver);
	ScoreBoard.createModel("../resources/staticmodels/scoreboard.obj", NULL, vector3df(0.0f, 0.0f, 0.0f), vector3df(0.0f, 0.0f, 0.0f), vector3df(0.5f, 0.5f, 0.5f), scnmgr, driver);
	Phonebooth.createModel("../resources/staticmodels/phone.obj", NULL, vector3df(10000.0f, 0.0f, 0.0f), vector3df(0.0f, 0.0f, 0.0f), vector3df(0.5f, 0.5f, 0.5f), scnmgr, driver);
	Judgetable.createModel("../resources/staticmodels/judgebuilding.obj", NULL, vector3df(800.0f, 0.0f, 0.0f), vector3df(0.0f, 0.0f, 0.0f), vector3df(0.5f, 0.5f, 0.5f), scnmgr, driver);
	Crash.createModel("../resources/staticmodels/crash.obj", NULL, vector3df(0.0f, 0.0f, 0.0f), vector3df(0.0f, 0.0f, 0.0f), vector3df(0.5f, 0.5f, 0.5f), scnmgr, driver);
	Stairs[0].createModel("../resources/staticmodels/steps.obj", NULL, vector3df(2500.0f, 0.0f, 0.0f), vector3df(0.0f, 0.0f, 0.0f), vector3df(0.5f, 0.5f, 0.5f), scnmgr, driver);
	Stairs[1].createModel("../resources/staticmodels/steps.obj", NULL, vector3df(-2500.0f, 0.0f, 0.0f), vector3df(0.0f, 180.0f, 0.0f), vector3df(0.5f, 0.5f, 0.5f), scnmgr, driver);
	Stairs[2].createModel("../resources/staticmodels/steps.obj", NULL, vector3df(0.0f, 0.0f, 2500.0f), vector3df(0.0f, -90.0f, 0.0f), vector3df(0.5f, 0.5f, 0.5f), scnmgr, driver);
	Stairs[3].createModel("../resources/staticmodels/steps.obj", NULL, vector3df(0.0f, 0.0f, -2500.0f), vector3df(0.0f, 90.0f, 0.0f), vector3df(0.5f, 0.5f, 0.5f), scnmgr, driver);

	
	

	//ANIMATED MESHES

	//Created our array (size:5) of objects of class characterModels, so we can use its functions.
	//Call the array then call the function to be stored in a single unit of the array
	//This helps when deleting and edit an object created through the same class
	/*CharacterModels myAnimatedCharacterModels[5];

	myAnimatedCharacterModels[0].createCharacter("../Resources/testing/sydney.md2", "../Resources/testing/sydney.bmp",
		vector3df(-60.0f, 0.0f, -60.0f), vector3df(0.0f, 90.0f, 0.0f), vector3df(1.0f, 1.0f, 1.0f), scnmgr, driver);
	*/
	
	//WATER ANIMATION (names needs to be changed)

	IAnimatedMesh *water = scnmgr->addHillPlaneMesh("pool",
		core::dimension2d<f32>(20, 20),//tile count
		core::dimension2d<u32>(40, 40), 0, 0,//materia
		core::dimension2d<f32>(0, 0),
		core::dimension2d<f32>(10, 10));
		

	ISceneNode *water_node = scnmgr->addWaterSurfaceSceneNode(water->getMesh(0), 5.0f, 200.0f, 30.0f);
	water_node->setPosition(vector3df(0, 10, -10000));


	//set the textures of the water
	water_node->setMaterialTexture(0, driver->getTexture("../resources/water.jpg"));
	water_node->setMaterialTexture(1, driver->getTexture("../resources/stones.jpg"));


	//REFLECTION LAYER OF THE WATER
	water_node->setMaterialType(video::EMT_REFLECTION_2_LAYER);

	scnmgr->setAmbientLight(SColor(255, 50, 50, 50));

	//BILLBOARDS

	BillBoard Plant[5];
	BillBoard Flags[5];

	Plant[1].createBillboard("../resources/StreetPlants.png", NULL, dimension2d<f32>(300.0f, 300.0f), vector3df(10000.0f, 0.0f, 0.0f), scnmgr, driver);
	Plant[2].createBillboard("../resources/StreetPlants.png", NULL, dimension2d<f32>(300.0f, 300.0f), vector3df(10000.0f, 0.0f, -100.0f), scnmgr, driver);
	Plant[3].createBillboard("../resources/StreetPlants.png", NULL, dimension2d<f32>(300.0f, 300.0f), vector3df(10000.0f, 0.0f, -200.0f), scnmgr, driver);
	Plant[4].createBillboard("../resources/StreetPlants.png", NULL, dimension2d<f32>(300.0f, 300.0f), vector3df(10000.0f, 0.0f, -300.0f), scnmgr, driver);
	Plant[5].createBillboard("../resources/StreetPlants.png", NULL, dimension2d<f32>(300.0f, 300.0f), vector3df(10000.0f, 0.0f, -400.0f), scnmgr, driver);

	Flags[1].createBillboard("../resources/flag.png", NULL, dimension2d<f32>(300.0f, 300.0f), vector3df(0.0f, 2000.0f, 0.0f), scnmgr, driver);
	Flags[2].createBillboard("../resources/flag.png", NULL, dimension2d<f32>(300.0f, 300.0f), vector3df(2000.0f, 2000.0f, 1000.0f), scnmgr, driver);
	Flags[3].createBillboard("../resources/flag.png", NULL, dimension2d<f32>(300.0f, 300.0f), vector3df(4000.0f, 2000.0f, 1000.0f), scnmgr, driver);
	Flags[4].createBillboard("../resources/flag.png", NULL, dimension2d<f32>(300.0f, 300.0f), vector3df(-2000.0f, 2000.0f, 1000.0f), scnmgr, driver);
	Flags[5].createBillboard("../resources/flag.png", NULL, dimension2d<f32>(300.0f, 300.0f), vector3df(-4000.0f, 2000.0f, 1000.0f), scnmgr, driver);



	//TERRAIN	
	//Memory notice
	/*Dimensions of the heightmaps original file increase the memory usage considerately,
	so ive made sure to keep the dimensisons below 300*/
	ITerrainSceneNode *terrain = scnmgr->addTerrainSceneNode(
		"../resources/Flat-Heightmap.png",//fielpath
		0,//parent
		1,//id
		vector3df(-10000.0f, -40.0f, -10000.0f),//position
		vector3df(0.0f, 0.0f, 0.0f),//rotation
		vector3df(100.0f, 0.0f, 100.0f),//scale
		SColor(255, 255, 255, 255),//colour
		5,//LOD(LEVEL OF DETAIL)
		ETPS_17,//terrain patch size
		4);

	if (terrain) {
		//	Write source code to turn the lighting off for the terrain
		terrain->setMaterialFlag(EMF_LIGHTING, false);

		//Write source code to load the terrain texture
		terrain->setMaterialTexture(0, driver->getTexture("../resources/GrassTexture.jpg"));

	}


	//SKYDOME
	//Used a whole sphere because the image allow it with no influence on memory
	/*I avoided using a skybox as the memory difference was 20mb during the tutorials
	I have also noticed the dimensions of the images also affects the frame rate*/
	scnmgr->addSkyDomeSceneNode(driver->getTexture("../resources/MySkydome.jpg"), 16, 16, 1.0f, 2.0f, 2000.0f);


	//CAMERA
	ICameraSceneNode *camera = scnmgr->addCameraSceneNodeFPS(0, 200, 5);
	camera->setPosition(vector3df(0.0f, 100.0f, 0.0f));
	camera->setFarValue(50000.0f);
	device->getCursorControl()->setVisible(false);

	//COLLISIONS WITH TERRAIN
	//source code to create triangle selector  
	ITriangleSelector *selector = scnmgr->createTerrainTriangleSelector(terrain, 0);
	terrain->setTriangleSelector(selector);

	//source code to create the collision response animator
	ISceneNodeAnimator *anim = scnmgr->createCollisionResponseAnimator(
		selector,
		camera,
		vector3df(60.0f, 100.0f, 60.0f),//Size of collision box
		vector3df(0.0f, 0.0f, 0.0f),//gravity
		vector3df(0.0f, 50.0f, 0.0f));

	//source code to add the animator to the camera
	if (anim) {
		selector->drop();
		camera->addAnimator(anim);
		anim->drop();
	}

	//GUI TEXT
	IGUIStaticText *guiText = device->getGUIEnvironment()->addStaticText(L"GUI text",
		rect<s32>(10, 10, 100, 30),
		true);


	//set up the fps
	s32 fps_then = driver->getFPS();

	//The force at which the object will be pushed
	const f32 MOVE_SPEED = 10.0f;

	//The calculation checks how long it was since the last frame
	u32 lastFrameTime = device->getTimer()->getTime();


	//Set up the game/drawing loop
	while (device->run())
	{
		//KEY EVENTS
		//CAMERA MOVEMENT

		//Get the current time
		u32 currentTime = device->getTimer()->getTime();

		//Calculate elasped time
		f32 elapsed = (currentTime - lastFrameTime) / 10.0f;

		//Store the camera position as a pointer
		vector3df camPosition = camera->getPosition();

		//Set frame time to current time to calculate next elapsed time
		lastFrameTime = currentTime;

		if (ker.IsKeyDown(KEY_KEY_W)) {
			camPosition.Z += MOVE_SPEED * elapsed;
		}
		if (ker.IsKeyDown(KEY_KEY_S)) {
			camPosition.Z -= MOVE_SPEED * elapsed;
		}
		if (ker.IsKeyDown(KEY_KEY_D)) {
			camPosition.X += MOVE_SPEED * elapsed;
		}
		if (ker.IsKeyDown(KEY_KEY_A)) {
			camPosition.X -= MOVE_SPEED * elapsed;
		}

		// Set new position based on input, if any
		camera->setPosition(camPosition);

		//EXIT SCENE
		if (ker.IsKeyDown(KEY_ESCAPE))
		{
			device->drop();
			return -1;

		}

		//CHARACTER JUMP
		if (ker.IsKeyDown(KEY_KEY_F)) {
			vector3df cam_pos = camera->getAbsolutePosition();

			cam_pos.Y += 10;

			camera->setPosition(cam_pos);
		}

		//SOUND CONTROLS

		//Play the sound and unpausing the sound
		if (ker.IsKeyDown(KEY_KEY_P)) {
			sound->setIsPaused(false);
		}
		//Set the paus value to 'true', pausing the track.
		if (ker.IsKeyDown(KEY_KEY_O)) {
			sound->setIsPaused(true);
		}
		//Play the song again from the beginning
		if (ker.IsKeyDown(KEY_KEY_L)) {
			sound->setPlayPosition(false);
		}


		//begin the scene
		driver->beginScene(true, true, SColor(255, 100, 101, 240));

		//draw the output to the screen using the scene manager
		scnmgr->drawAll();


		//get the current frame rate
		s32 fps_now = driver->getFPS();

		//if there has been a chang in frame rate 
		if (fps_now != fps_then) {

			//then update window caption bar
			stringw msg = "FPS = ";
			msg += fps_now;

			guiText->setText(msg.c_str());


			//Update frame rate
			fps_then = fps_now;
		}

		//Update the GUI.  Need to invoke drawAll frequently otherwise won't see any change in GUI or no GUI at all.
		device->getGUIEnvironment()->drawAll();

		//end the scene
		driver->endScene();

	}

	//clear the irrklang device
	engine->drop();

	//clear the video device
	device->drop();

	return -1;
}

