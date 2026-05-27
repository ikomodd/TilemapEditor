#pragma once

#include <SDL3/SDL.h>

struct color4 {

	Uint8 R, G, B, A;

	color4(Uint8 r = 255, Uint8 g = 255, Uint8 b = 255, Uint8 a = 255): R(r), G(g), B(b), A(a) {}
	color4(int all) : R(all), G(all), B(all), A(255) {}

	// +=

	color4 operator += (const int value) {

		R += value;
		G += value;
		B += value;

		return *this;
	}

	// -=

	color4 operator -= (const int value) {

		R -= value;
		G -= value;
		B -= value;

		return *this;
	}
};