#pragma once

struct vector2;

struct ivector2 {

	int X, Y;

	ivector2(int x = 0, int y = 0) : X(x), Y(y) {}

	// Soma

	ivector2 operator + (const ivector2& other) const {

		return ivector2(X + other.X, Y + other.Y);
	}

	// Subtração

	ivector2 operator - (const ivector2& other) const {

		return ivector2(X - other.X, Y - other.Y);
	}

	// Multiplicação

	ivector2 operator * (const ivector2& other) const {

		return ivector2(X * other.X, Y * other.Y);
	}

	ivector2 operator * (const int& value) const {

		return ivector2(X * value, Y * value);
	}

	// Igual

	bool operator == (const ivector2& other) const {

		return X == other.X && Y == other.Y;
	}

	// Maior

	bool operator < (const ivector2& other) const {

		if (X != other.X) return X < other.X;
		return Y < other.Y;
	}

	//

	vector2 ToVector2();
};