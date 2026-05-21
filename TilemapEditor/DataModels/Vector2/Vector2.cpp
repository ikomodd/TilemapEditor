#include "Vector2.h"
#include  "iVector2.h"

#include <string>
#include <algorithm>

#include <math.h>

vector2 ivector2::ToVector2() {

	return vector2(static_cast<float>(X), static_cast<float>(Y));
}

//

//vector2 vector2::Units() {
//
//	return vector2(X * KMD_Core::UnitSize, Y * KMD_Core::UnitSize);
//}

//

vector2 vector2::Units()
{
	return vector2();
}

float vector2::Magnitude() const {

	return std::sqrt(X * X + Y * Y);
}

vector2 vector2::Normalize() const {

	float MagnitudeValue = Magnitude();

	if (MagnitudeValue == 0.0f) return vector2();

	return *this / MagnitudeValue;
}

vector2 vector2::Lerp(vector2 end, float alpha) {

	return {

		X + (end.X - X) * alpha,
		Y + (end.Y - Y) * alpha,
	};
}

vector2 vector2::Clamp(vector2 min, vector2 max) {

	return vector2(std::clamp(X, min.X, max.X), std::clamp(Y, min.Y, max.Y));
}

vector2 vector2::Floor() {

	return vector2(std::floor(X), std::floor(Y));
}

std::string vector2::ToString() {

	return "vector2(" + std::to_string(X) + ", " + std::to_string(Y) + ")";
}

ivector2 vector2::ToiVector2() {
	return ivector2((int)std::floor(X), (int)std::floor(Y));
}