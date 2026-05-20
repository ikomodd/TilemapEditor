#pragma once

struct vector2;

struct ivector2 {

	int X, Y;

	ivector2(int x = 0, int y = 0) : X(x), Y(y) {}

	//

	bool operator == (const ivector2& other) const {

		return X == other.X && Y == other.Y;
	}

	bool operator < (const ivector2& other) const {

		if (X != other.X) return X < other.X;
		return Y < other.Y;
	}

	//

	vector2 ToVector2();
};