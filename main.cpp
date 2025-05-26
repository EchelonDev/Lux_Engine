#define SDL_MAIN_HANDLED


#include <SDL3/SDL.h>
#include "Game.h"

#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	bool running = true;

	Game* game = new Game();
	game->LuxStartWindowWithRenderer("test", 1024, 780, 0, NULL);

	game->Run();

	delete game;
	return 0;

	
}




/*

TODO:
	- Uncomment PhysicsComponent Codes after creating Vec2 struct

	- Create SpriteComponent



	- Later: ***** 

	- Later: Check the naming

	- Later: Deal with .h and .cpp files

*/