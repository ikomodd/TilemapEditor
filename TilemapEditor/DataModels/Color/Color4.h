#pragma once

#include <SDL3/SDL.h>

struct color4 {

	enum Color {

		RED,
		GREEN,
		BLUE,

		WHITE,
		BLACK,
		CLEAR
	};

	Uint8 R, G, B, A;

	color4(Uint8 r = 255, Uint8 g = 255, Uint8 b = 255, Uint8 a = 255): R(r), G(g), B(b), A(a) {}

	static color4 GetColor(Color color) {

		switch (color)
		{
		case color4::RED: return color4(255, 0, 0, 255);
			break;
		case color4::GREEN: return color4(0, 255, 0, 255);
			break;
		case color4::BLUE: return color4(0, 0, 255, 255);
			break;
		case color4::WHITE: return color4(255, 255, 255, 255);
			break;
		case color4::BLACK: return color4(0, 0, 0, 255);
			break;
		case color4::CLEAR: return color4(0, 0, 0, 0);
			break;
		default:
			break;
		}
	}
};