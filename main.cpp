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