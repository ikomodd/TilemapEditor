#pragma once

#include "../Node.h"
#include "../../Inheritance/Transform/WorldTransform/WorldTransform.h"

class GAME_Node2D : public GAME_Node, public GAME_WorldTransform {
public:

	GAME_Node2D(std::string name, vector2 position, vector2 size = vector2(), vector2 offset = vector2()) : GAME_Node(name), GAME_WorldTransform(position, size, offset) {}

	void _Draw(SDL_Renderer* renderer) override {

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderPoint(renderer, GlobalPosition.X, GlobalPosition.Y);
	}
};