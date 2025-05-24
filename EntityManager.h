#pragma once

#include "Entity.h"

#include <vector>
#include <memory>

class EntityManager {

public:
	Entity& CreateEntity(float id)
	{
		int id = nextId_++;
		entities_.push_back(std::make_unique<Entity>(id));
		return *entities_.back();
	}

	void UpdateAll(float deltaTime)
	{
		for (auto& entity : entities_) entity->Update(deltaTime);
	}

	void DrawAll(SDL_Renderer* renderer)
	{
		for (auto& entity : entities_) entity->Draw(renderer);
	}



private:
	int nextId_ = 0;

	std::vector<std::unique_ptr<Entity>> entities_;
};
