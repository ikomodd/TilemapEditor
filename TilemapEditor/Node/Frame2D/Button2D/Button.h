#pragma once

#include "../TextLabel2D/TextLabel2D.h"
#include "../../../Utility/Event/Event.h"

class GAME_Button2D : public GAME_TextLabel2D {
private:

	bool Floating = false;

public:

	GAME_Event<> OnClicked;

	GAME_Button2D(std::string name, std::string font_path, vector2 position, vector2 size, vector2 anchor = 0, float font_scale = 0.05f, color4 background_color = 255, color4 border_color = 0, float border_size = 0) : GAME_TextLabel2D(name, font_path, position, size, anchor, font_scale, background_color, border_color, border_size) {

		VerticalAlign = VERTICAL_ALIGN_CENTER;
		HorizontalAlign = HORIZONTAL_ALIGN_CENTER;
	}

	void _Event(SDL_Event& event) override;

	virtual void _Clicked() {}
};