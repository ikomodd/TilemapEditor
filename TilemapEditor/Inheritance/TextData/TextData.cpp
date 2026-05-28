#include "TextData.h"

GAME_TextData::GAME_TextData(std::string font_path, float scale) {

	ChangeFont(font_path, scale);
}

void GAME_TextData::ChangeText(std::string text, color4 color) {

	auto& Display = GAME_DisplayCore::Get();

	if (TextSurface)
		SDL_DestroySurface(TextSurface);
	if (TextTexture)
		SDL_DestroyTexture(TextTexture);

	Color = color;

	TextSurface = TTF_RenderText_Blended(Font, text.c_str(), 0, SDL_Color(color.R, color.G, color.B, color.A));
	TextTexture = SDL_CreateTextureFromSurface(Display.Renderer, TextSurface);

	Text = text;
}

void GAME_TextData::ChangeFont(std::string font_path, float scale) {

	auto* FontAsset = GAME_AssetCore::Get().GetItem<ASSET_FontSource>(font_path, scale);

	if (FontAsset) {
		Font = FontAsset->Font;

		FontPath = font_path;
		FontScale = scale;

		if (!Text.empty())
			ChangeText(Text, Color);
	}
}
