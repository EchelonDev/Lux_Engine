#define SDL_MAIN_HANDLED

#pragma once
#include <SDL3/SDL.h>



class Game
{

public:

	bool running;

	SDL_Window* window;
	SDL_Renderer* renderer;
	//SDL_Event event;

	Game();

	// Main loop
	void Run();

	// Create a Window and Renderer using SDL
	void LuxStartWindowWithRenderer(const char* title, int w, int h, SDL_WindowFlags flags, const char* renderingDriver);

	// Handeling inputs events and events
	int HandleEvent();

	// Spawning elements
	void BuildingWorld();

	// Destroy and cleanup the Subsystems
	void LuxShutdown();

	// Log in Console
	const char* LuxLog(const char* text);

	// Error Log in Console
	const char* LuxLogError(const char* text);
};

