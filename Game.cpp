#define SDL_MAIN_HANDLED

#include "Game.h"
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include <iostream>
//using namespace std;


Game::Game()
{
	running = true;
}

const char* Game::LuxLog(const char* text)
{
	std::cout << text << std::endl;
	return text;
}

const char* Game::LuxLogError(const char* text)
{
	std::cerr << text << std::endl;
	return text;
}

void Game::LuxShutdown()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	running = false;
}

void Game::LuxStartWindowWithRenderer(const char* title, int w, int h, SDL_WindowFlags flags, const char* renderingDriver)
{
	window = SDL_CreateWindow(title, w, h, 0);
	if (!window)
	{
		LuxLogError("INITIALIZING A WINDOW HAS FAILED: ");
		LuxLogError(SDL_GetError());
		SDL_Quit();
	}

	renderer = SDL_CreateRenderer(window, renderingDriver);
	if (!renderer)
	{
		LuxLogError("INITIALIZING A RENDERER HAS FAILDED");
		LuxLogError(SDL_GetError());
		SDL_DestroyWindow(window);
		SDL_Quit();
	}
}

int Game::HandleEvent()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_EVENT_QUIT)
		{
			LuxShutdown();
			return 1;
		}

		if (event.type == SDL_EVENT_KEY_DOWN && event.key.key == SDLK_ESCAPE)
		{
			LuxShutdown();
			return 1;
		}
	}
	return 0;
}

void Game::BuildingWorld()
{

}

void Game::Run()
{
	while (running)
	{
		HandleEvent();
		
		BuildingWorld();
	}
}
