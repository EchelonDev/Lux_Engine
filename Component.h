#pragma once

#include <SDL3/SDL.h>

class Entity;

class Component
{
public:
	Component(Entity& owner) : owner_(owner) {}

	virtual ~Component() = default;

	// Called each frame
	virtual void Update(float deltaTime) {};

	// Render using SDL Renderer
	virtual void Draw(SDL_Renderer* renderer) {};

protected:
	Entity& owner_;
};

