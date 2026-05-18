#pragma once

#include "../Node2D/Node2D.h"
#include "../../Inheritances/SpriteData/SpriteData.h"

class GAME_Sprite2D : public GAME_Node2D, public GAME_SpriteData {
public:

	GAME_Sprite2D(std::string name, vector2 position, vector2 size, vector2 offset, std::string path) : GAME_Node2D(name, position, size, offset), GAME_SpriteData(path) {};

	void _Draw(SDL_Renderer* renderer) override;
};