#pragma once

#include "../Node2D/Node2D.h"

class GAME_Camera2D : public GAME_Node2D {
public:

	GAME_Camera2D(std::string name, vector2 position, vector2 size, vector2 offset);

	SDL_FRect InCameraView (SDL_FRect rect);
};