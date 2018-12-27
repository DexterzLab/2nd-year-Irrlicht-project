#include <irrlicht.h>
using namespace irr;

//Adapted from Rytz 2008. http://irrlicht.sourceforge.net/forum/viewtopic.php?t=29139&view=next&sid=3fa2a975c8abd1ccff1778deb852ac90

class KeyReceiver : public IEventReceiver
{
public:
	
	// -------------------------------------
	// KeyEventReceiver Method Declarations
	// -------------------------------------

	//Constructor initialises array to indicate all keys are not pressed
	KeyReceiver();

	//Returns the state of a key, true is pressed and false is not pressed
	virtual bool IsKeyDown(EKEY_CODE keyCode) const;

	//Invoked by irrlicht when an event occurs.
	virtual bool OnEvent(const SEvent& event);

private:

	//stores the state of all keys
	bool KeyIsDown[KEY_KEY_CODES_COUNT];


	
};

