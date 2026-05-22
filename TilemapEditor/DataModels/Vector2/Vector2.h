#pragma once

#include <iostream>

struct ivector2;

struct vector2 {

	inline static float EpsValue = 0.003f;

	float X, Y;

	//

	vector2(float x = 0, float y = 0) : X(x), Y(y) {};

	vector2(float all) : X(all), Y(all) {}
	vector2(int all) : X((float)all), Y((float)all) {}


	// Soma
	
	vector2 operator + (const vector2& other) const {

		return vector2(X + other.X, Y + other.Y);
	}

	vector2 operator += (const vector2& other) {

		X += other.X;
		Y += other.Y;

		return *this;
	}

	// Subtração

	vector2 operator - (const vector2& other) const {

		return vector2(X - other.X, Y - other.Y);
	}

	vector2 operator -= (const vector2& other) {

		X -= other.X;
		Y -= other.Y;

		return *this;
	}
	
	// Multiplicação

	vector2 operator * (const float& value) const {

		return vector2(X * value, Y * value);
	}

	vector2 operator * (const vector2& other) const {

		return vector2(X * other.X, Y * other.Y);
	}

	vector2 operator *= (const vector2& other) {

		X *= other.X;
		Y *= other.Y;

		return *this;
	}

	// Divisao

	vector2 operator / (const float& value) const {

		return vector2(X / value, Y / value);
	}

	vector2 operator / (const vector2& other) const {

		return vector2(X / other.X, Y / other.Y);
	}

	vector2 operator /= (const vector2& other) {

		X /= other.X;
		Y /= other.Y;

		return *this;
	}

	// Igual

	bool operator == (const vector2& other) const {

		return std::abs(X - other.X) < EpsValue && std::abs(Y - other.Y) < EpsValue;
	}

	// Diferente

	bool operator != (const vector2& other) const {

		return !(*this == other);
	}

	//

	vector2 Units();

	float Magnitude() const;
	vector2 Normalize() const;
	vector2 Lerp(vector2 end, float alpha);
	vector2 Clamp(vector2 min, vector2 max);
	vector2 Floor();

	std::string ToString();
	ivector2 ToiVector2();
};