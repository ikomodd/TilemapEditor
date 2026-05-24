#include "AssetCore.h"

#include <algorithm>

#include "../Display/DisplayCore.h"

ASSET_SpriteSource::ASSET_SpriteSource(std::string path) : ASSET_Source(path) {

	auto& Display = GAME_DisplayCore::Get();

	Surface = IMG_Load(path.c_str());

	if (!Surface) {
		std::cerr << "[ASSET_SPRITE] nao ha nenhum asset valido em: " << path << "\n";
		return;
	}

	Texture = SDL_CreateTextureFromSurface(Display.Renderer, Surface);
}

ASSET_FontSource::ASSET_FontSource(std::string path, float scale) : Scale(scale), ASSET_Source(path) {

	auto& Display = GAME_DisplayCore::Get();

	float Minimum = std::min(Display.WindowSize.X, Display.WindowSize.Y);
	float FontSize = Minimum * scale;

	Font = TTF_OpenFont(path.c_str(), FontSize);

	if (!Font)
		std::cerr << "[ASSET_FONT] nao ha nenhuma fonte TTF valida em: " << path << "\n" << SDL_GetError() << "\n";
}

//

void GAME_AssetCore::WindowResized(vector2 window_size) {

	for (auto asset : Sources) {

		auto* FontAsset = dynamic_cast<ASSET_FontSource*>(asset.second);
		if (FontAsset) {

			if (FontAsset->Font) {
				TTF_CloseFont(FontAsset->Font);
				FontAsset->Font = nullptr;
			}

			float Minimum = std::min(window_size.X, window_size.Y);
			float FontSize = Minimum * FontAsset->Scale;

			FontAsset->Font = TTF_OpenFont(FontAsset->Path.c_str(), FontSize);
		}
	}
}

void GAME_AssetCore::_Init() {

	auto& Display = GAME_DisplayCore::Get();

	Display.WindowResized.Connect([this](vector2 window_size) {

		WindowResized(window_size);
	});
}
