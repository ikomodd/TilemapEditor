#pragma once

#include "../Panel2D/Panel2D.h"
#include "../../../Inheritance/TextData/TextData.h"

class GAME_TextLabel2D : public GAME_Panel2D, public GAME_TextData {
public:

	GAME_TextLabel2D(std::string name, std::string font_path, std::string background_path, vector2 position, vector2 size, vector2 anchor = 0, float font_scale = 0.05f, color4 background_color = 255, color4 border_color = 0, float border_size = 0) : GAME_Panel2D(name, background_path, position, size, anchor, background_color, border_color, border_size), GAME_TextData(font_path, font_scale) {}

	void _Ready() override;
	void _Draw(SDL_Renderer* renderer) override;
};