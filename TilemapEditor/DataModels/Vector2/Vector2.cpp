#include "Vector2.h"
#include  "iVector2.h"

#include <math.h>

#include "../Core.h"

vector2 ivector2::ToVector2() {

	return vector2(static_cast<float>(X), static_cast<float>(Y));
}

//

std::string vector2::ToString() {

	return "vector2(" + std::to_string(X) + ", " + std::to_string(Y) + ")";
}

//vector2 vector2::Units() {
//
//	return vector2(X * KMD_Core::UnitSize, Y * KMD_Core::UnitSize);
//}

//

float vector2::Magnitude() const {

	return std::sqrt(X * X + Y * Y);
}

vector2 vector2::Normalize() const {

	float MagnitudeValue = Magnitude();

	if (MagnitudeValue == 0.0f) return vector2::Zero();

	return *this / MagnitudeValue;
}

vector2 vector2::Lerp(vector2 end, float alpha) {

	return {

		X + (end.X - X) * alpha,
		Y + (end.Y - Y) * alpha,
	};
}