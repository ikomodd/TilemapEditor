#pragma once

#include "../Node.h"
#include "../../Inheritances/Transform/Transform.h"

class GAME_Node2D : public GAME_Node, public GAME_Transform {
public:

	GAME_Node2D(std::string name, vector2 position, vector2 size = vector2(), vector2 offset = vector2()) : GAME_Node(name), GAME_Transform(position, size, offset) {}

	void _Draw(SDL_Renderer* renderer) override {

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderPoint(renderer, GlobalPosition.X, GlobalPosition.Y);
	}
};