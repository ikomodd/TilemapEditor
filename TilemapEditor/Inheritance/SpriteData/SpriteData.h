#pragma once

#include <iostream>
#include <SDL3/SDL.h>

#include "../../DataModels/Color/Color4.h"

class GAME_SpriteData {
public:
	
	SDL_Texture* Texture;
	SDL_Surface* Surface;

	GAME_SpriteData(std::string path) {

		ChangeTexture(path);
	}

	void ChangeTexture(std::string path);
};