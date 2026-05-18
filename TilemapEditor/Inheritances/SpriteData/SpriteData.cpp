#include "SpriteData.h"

#include "../../Singleton/Asset/AssetCore.h"

void GAME_SpriteData::ChangeTexture(std::string path) {

	ASSET_SpriteSource* Asset = GAME_AssetCore::Get().GetItem<ASSET_SpriteSource>(path);
	if (Asset) {

		if (Texture) {
			SDL_DestroyTexture(Texture);
			Texture = nullptr;
		}
		if (Surface) {
			SDL_DestroySurface(Surface);
			Surface = nullptr;
		}

		Texture = Asset->Texture;
		Surface = Asset->Surface;
	}
}
