#pragma once

#include <vector>
#include <memory>

class Component;
class SDL_Renderer;

using ComponentPtr = std::unique_ptr<Component>;



class Entity
{
public: 
	Entity(int id);

	void Update(float dt);

	void Draw(SDL_Renderer* renderer);

	template<typename T, typename... Args>
	T& AddComponent(Args&&... args)
	{
		auto component = std::make_unique<T>(std::forward(args)...);

		T& ref = *component;

		components_.push_back(std::move(component));

		return ref;
	}

	template<typename T>
	T* GetComponent()
	{
		for (auto& c : components_) {
			if (auto ptr = dynamic_cast<T*>(c.get()))
				return ptr;
		}
		return nullptr;
	}

private:
	int id_;

	std::vector<ComponentPtr> components_;
};

