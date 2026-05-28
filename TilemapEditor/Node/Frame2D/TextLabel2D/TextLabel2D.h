#pragma once

#include "../Panel2D/Panel2D.h"
#include "../../../Inheritance/TextData/TextData.h"

class GAME_TextLabel2D : public GAME_Panel2D, public GAME_TextData {
public:

	FRAME_VerticalAlign VerticalAlign = VERTICAL_ALIGN_TOP;
	FRAME_HorizontalAlign HorizontalAlign = HORIZONTAL_ALIGN_LEFT;

	GAME_TextLabel2D(std::string name, std::string font_path, float font_scale, vector2 position, vector2 size, vector2 anchor = 0, color4 background_color = 150, color4 border_color = 0, float border_size = 0.f) : GAME_Panel2D(name, position, size, anchor, background_color, border_color, border_size), GAME_TextData(font_path, font_scale) {}

	void _Ready() override;
	void _Draw(SDL_Renderer* renderer) override;
};