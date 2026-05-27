#pragma once

#include "../Node.h"
#include "../../Inheritance/Transform/UiTransform/UiTransform.h"

class GAME_Frame2D : public GAME_Node, public GAME_UiTransform {
public:

	bool StopMouse = true;

	GAME_Frame2D(std::string name, vector2 position, vector2 size, vector2 anchor) : GAME_Node(name), GAME_UiTransform(position, size, anchor) {};

	bool HasCollision(vector2 position) {

		if (!StopMouse) return false;
		
		SDL_FRect Rect = { GlobalPosition.X, GlobalPosition.Y, GlobalSize.X, GlobalSize.Y };
		SDL_FPoint Point = { position.X, position.Y };

		return SDL_PointInRectFloat(&Point, &Rect);
	}
};