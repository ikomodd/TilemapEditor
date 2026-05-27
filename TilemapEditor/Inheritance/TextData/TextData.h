#pragma once

#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>

#include "../../Singleton/Display/DisplayCore.h"
#include "../../Singleton/Asset/AssetCore.h"

#include "../../DataModels/Color/Color4.h"

class GAME_TextData {
private:

	std::string Text = "";

	TTF_Font* Font = nullptr;

protected:

	std::string FontPath = "";
	float FontScale = 0;

	color4 Color = 0;

	SDL_Texture* TextTexture = nullptr;
	SDL_Surface* TextSurface = nullptr;

public:

	enum FRAME_VerticalAlign {

		VERTICAL_ALIGN_TOP,
		VERTICAL_ALIGN_CENTER,
		VERTICAL_ALIGN_BOTTOM,
	};

	enum FRAME_HorizontalAlign {

		HORIZONTAL_ALIGN_LEFT,
		HORIZONTAL_ALIGN_CENTER,
		HORIZONTAL_ALIGN_RIGHT,
	};

	GAME_TextData(std::string font_path, float scale);

	void ChangeText(std::string text);
	void ChangeFont(std::string font_path, float scale);
};