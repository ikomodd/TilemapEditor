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

	GAME_TextData(std::string font_path, float scale) {

		ChangeFont(font_path, scale);
	}

	void ChangeText(std::string text) {

		auto& Display = GAME_DisplayCore::Get();

		if (TextSurface)
			SDL_DestroySurface(TextSurface);
		if (TextTexture)
			SDL_DestroyTexture(TextTexture);

		TextSurface = TTF_RenderText_Blended(Font, text.c_str(), 0, SDL_Color(Color.R, Color.G, Color.B, Color.A));
		TextTexture = SDL_CreateTextureFromSurface(Display.Renderer, TextSurface);

		Text = text;
	}

	void ChangeFont(std::string font_path, float scale) {

		auto* FontAsset = GAME_AssetCore::Get().GetItem<ASSET_FontSource>(font_path, scale);

		if (FontAsset) {
			Font = FontAsset->Font;

			FontPath = font_path;
			FontScale = scale;

			if (!Text.empty())
				ChangeText(Text);
		}
	}
};