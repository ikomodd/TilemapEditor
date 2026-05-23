#pragma once

#include "../Transform.h"

class GAME_WorldTransform : public GAME_Transform {
public:

	vector2 GlobalPosition;
	vector2 LocalPosition;

	vector2 Offset;
	vector2 Size;

	GAME_WorldTransform(vector2 local_position, vector2 size, vector2 offset = vector2(0.0f, 0.0f)) : LocalPosition(local_position), Size(size), Offset(offset) {};

	void UpdateTransform() override;
};