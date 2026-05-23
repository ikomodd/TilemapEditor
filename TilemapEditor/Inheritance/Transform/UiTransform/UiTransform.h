#pragma once

#include "../Transform.h"

class GAME_UiTransform : public GAME_Transform{
public:

	vector2 Anchor;

	vector2 GlobalPosition;
	vector2 LocalPosition;

	vector2 GlobalSize;
	vector2 LocalSize;

	GAME_UiTransform(vector2 local_position, vector2 local_size, vector2 anchor) : LocalPosition(local_position), LocalSize(local_size), Anchor(anchor) {}

	void UpdateTransform() override;
};