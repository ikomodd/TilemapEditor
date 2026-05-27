#pragma once

#include "../Frame2D.h"
#include "../../../Inheritance/SpriteData/SpriteData.h"

class GAME_Panel2D : public GAME_Frame2D {
public:

	color4 SolidColor;

	color4 BorderColor;
	float BorderSize = 10.f;

	GAME_Panel2D(std::string name, vector2 position, vector2 size, vector2 anchor = 0, color4 solid_color = 200, color4 border_color = 150, float border_size = 1) : BorderColor(border_color), BorderSize(border_size), SolidColor(solid_color), GAME_Frame2D(name, position, size, anchor) {}

	void _Draw(SDL_Renderer* renderer) override;
};