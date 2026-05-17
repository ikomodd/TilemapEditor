#pragma once

#include <SDL3/SDL.h>

#include "../Singleton.h"

#include "../../DataModels/Vector2/Vector2.h"
#include "../../DataModels/Color/Color4.h"

class GAME_DisplayCore : public CORE_Singleton<GAME_DisplayCore> {
public:

	SDL_Window* Window = nullptr;
	SDL_Renderer* Renderer = nullptr;

	color4 BackgroundColor = color4(125, 125, 125, 255);

	vector2 WindowSize;

private:

	GAME_DisplayCore() : CORE_Singleton("DisplayCore", 1) {}
	friend class CORE_Singleton<GAME_DisplayCore>;

	void ConfigureWindowSize();

	void _Init() override;
	void _Event(SDL_Event& event) override;
	void _Process(float delta) override;
	void _Exit() override;
};