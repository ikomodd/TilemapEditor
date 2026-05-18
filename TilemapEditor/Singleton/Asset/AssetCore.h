#pragma once

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <map>

#include "../Singleton.h"

struct ASSET_Source {

	std::string Path;

	ASSET_Source(std::string path) : Path(path) {}
	virtual ~ASSET_Source() {}
};

struct ASSET_SpriteSource : public ASSET_Source{

	SDL_Texture* Texture;
	SDL_Surface* Surface;

	ASSET_SpriteSource(std::string path, SDL_Texture* texture, SDL_Surface* surface) : Texture(texture), Surface(surface), ASSET_Source(path) {}
};

//

class GAME_AssetCore : public CORE_Singleton<GAME_AssetCore> {
private:

	std::map<std::string, ASSET_Source*> Sources;

	GAME_AssetCore() {}
	friend class CORE_Singleton<GAME_AssetCore>;

	ASSET_Source* LoadTexture(std::string path);

public:

	template <typename T>
	T* GetItem(std::string path) {

		auto Asset = Sources.find(path);

		T* Result = nullptr;

		if (Asset == Sources.end())
			Result = dynamic_cast<T*>(LoadTexture(path));
		else
			Result = dynamic_cast<T*>(Asset->second);

		return Result;
	}
};