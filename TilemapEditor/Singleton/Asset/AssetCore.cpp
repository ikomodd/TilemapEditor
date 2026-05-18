#include "AssetCore.h"

#include "../Display/DisplayCore.h"

ASSET_Source* GAME_AssetCore::LoadTexture(std::string path) {

	SDL_Renderer* Renderer = GAME_DisplayCore::Get().Renderer;

	SDL_Surface* Surface = IMG_Load(path.c_str());

	if (!Surface) {
		std::cerr << "[ASSET_CORE] nao ha nenhum asset valido em: " << path << "\n";
		return nullptr;
	}

	SDL_Texture* Texture = SDL_CreateTextureFromSurface(Renderer, Surface);

	auto* Asset = new ASSET_SpriteSource(path, Texture, Surface);
	Sources[path] = Asset;

	return Asset;
}
