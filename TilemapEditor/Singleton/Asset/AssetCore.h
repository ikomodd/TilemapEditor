#pragma once

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_ttf/SDL_ttf.h>

#include <iostream>
#include <map>

#include "../../DataModels/Vector2/Vector2.h"

#include "../Singleton.h"

struct ASSET_Source {

	std::string Path;

	ASSET_Source(std::string path) : Path(path) {}
	virtual ~ASSET_Source() {}
};

struct ASSET_SpriteSource : public ASSET_Source{

	SDL_Texture* Texture = nullptr;
	SDL_Surface* Surface = nullptr;

	ASSET_SpriteSource(std::string path);
};

struct ASSET_FontSource : ASSET_Source {

	float Scale;
	TTF_Font* Font = nullptr;

	ASSET_FontSource(std::string path, float scale);
};

//

class GAME_AssetCore : public CORE_Singleton<GAME_AssetCore> {
private:

	std::map<std::string, ASSET_Source*> Sources;

	GAME_AssetCore() {}
	friend class CORE_Singleton<GAME_AssetCore>;

public:

	template <typename T, typename... Args>
	T* GetItem(std::string path, Args&&... args) {

		if (path.empty())
			return nullptr;

		auto Asset = Sources.find(path);

		T* Result = nullptr;

		if (Asset == Sources.end()) {

			T* Source = new T(path, std::forward<Args>(args)...);
			Sources[path] = Source;

			Result = Source;

			std::cout << "[ASSET_CORE] arquivo carregado na memoria: " << path << ". " << Sources.size() << " arquivos totais\n";
		}
		else
			Result = dynamic_cast<T*>(Asset->second);

		return Result;
	}

private:

	void WindowResized(vector2 window_size);

	void _Init() override;
};