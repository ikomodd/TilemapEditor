#pragma once

#include <iostream>
#include <SDL3/SDL.h>

#include "../../DataModels/Color/Color4.h"

class GAME_SpriteData {
public:
	
	SDL_Texture* Texture;
	SDL_Surface* Surface;

	color4 SolidColor;

	GAME_SpriteData(std::string path, color4 solid_color = color4(255)) : SolidColor(solid_color) {

		ChangeTexture(path);
	}

	void ChangeTexture(std::string path);
};