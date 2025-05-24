#pragma once

#include "Component.h"


class PhysicsComponent : public Component {
public:
	PhysicsComponent(Entity& Owner, float mass = 1.0f) : Component(Owner), mass_(mass) {}

	// To Uncomment after creating Vec2 Struct

	/*void Update(float deltaTime) override {

		Velocity_.y += 9.8f * deltaTime;

		Position_ += Velocity_ * deltaTime;
	}


	// Simple Getters/Setters
	void SetVelocity(const vec2& Velocity) { Velocity_ = Velocity; }

	Vec2 GetPosition() const { return Position_; }

private:
	

	vec2 Position_{ 0,0 };

	vec2 Velocity_{ 0,0 };*/
	
	float mass_;

};