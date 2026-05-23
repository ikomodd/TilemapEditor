#pragma once

#include "../Node.h"
#include "../../Inheritance/Transform/UiTransform/UiTransform.h"

class GAME_Frame2D : public GAME_Node, public GAME_UiTransform {
public:

	GAME_Frame2D(std::string name, vector2 position, vector2 size, vector2 anchor) : GAME_Node(name), GAME_UiTransform(position, size, anchor) {};

	void _Draw(SDL_Renderer* renderer) {

		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

		SDL_FRect Rect = { GlobalPosition.X, GlobalPosition.Y, GlobalSize.X, GlobalSize.Y };
		SDL_RenderFillRect(renderer, &Rect);
	}
};