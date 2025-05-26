#pragma once

#include <cmath>
#include<iostream>

struct Vector2 {

	float x;

	float y;

	// Constructors
	Vector2() : x(0.0f), y(0.0f) {}
	Vector2(float x, float y) : x(x), y(y) {}

	// Operators
	Vector2 operator+(const Vector2& other)
	{
		return Vector2(x + other.x, y + other.y);
	}

	Vector2& operator+=(const Vector2& other)
	{
		x += other.x;
		y += other.y;
		return *this;
	}

	Vector2 operator-(const Vector2& other)
	{
		return Vector2(x - other.x, y - other.y);
	}

	Vector2& operator-=(const Vector2& other)
	{
		x -= other.x;
		y -= other.y;
		return *this;
	}

	Vector2 operator*(const Vector2& other)
	{
		return Vector2(x * other.x, y * other.y);
	}

	Vector2& operator*=(const Vector2& scalar)
	{
		x *= scalar.x;
		y *= scalar.y;
		return *this;
	}
	
	Vector2 operator/(const Vector2& scalar)
	{
		return Vector2(x / scalar.x, y / scalar.y);
	}

	Vector2& operator/=(const Vector2& scalar)
	{
		x /= scalar.x;
		y /= scalar.y;
		return *this;
	}

	// Utilities 
	float Magnitude() const
	{
		return std::sqrtf(x * x + y * y);
	}

	Vector2 Normalized() const
	{
		float mag = Magnitude();
		if (mag == 0) return Vector2(0, 0);
		return Vector2(x / mag, y / mag);
	}

	float Normalize()
	{
		float mag = Magnitude();
		if (mag != 0)
		{
			x /= mag;
			y /= mag;
		}
	}

	float Dot(Vector2& other) const
	{
		return x * other.x + y * other.y;
	}

	// Debug
	void PrintVec()
	{
		std::cout << "Vector2 (" << x << ", " << y << ")" << std::endl;
	}
};
