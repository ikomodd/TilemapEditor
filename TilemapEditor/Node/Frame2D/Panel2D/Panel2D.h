#pragma once

#include "../Frame2D.h"
#include "../../../Inheritance/SpriteData/SpriteData.h"

class GAME_Panel2D : public GAME_Frame2D, public GAME_SpriteData {
public:

	color4 BorderColor;
	float BorderSize = 10.f;

	GAME_Panel2D(std::string name, std::string texture_path, vector2 position, vector2 size, vector2 anchor = 0, color4 solid_color = 255, color4 border_color = 0, float border_size = 0) : BorderColor(border_color), BorderSize(border_size), GAME_Frame2D(name, position, size, anchor), GAME_SpriteData(texture_path, solid_color) {}

	void _Draw(SDL_Renderer* renderer) override;
};