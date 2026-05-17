#pragma once

struct vector2;

struct ivector2 {

	int X, Y;

	ivector2(int x = 0, int y = 0) : X(x), Y(y) {}

	//

	vector2 ToVector2();
};