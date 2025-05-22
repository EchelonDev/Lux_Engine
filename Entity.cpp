#include "Entity.h"

#include "Component.h"

Entity::Entity(int id) : id_(id) {};

void Entity::Update(float deltaTime)
{
	for (auto& c : components_) c->Update(deltaTime);
}

void Entity::Draw(SDL_Renderer* renderer)
{
	for (auto& c : components_) c->Draw(renderer);
}