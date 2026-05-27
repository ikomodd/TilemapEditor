#pragma once

#include <SDL3/SDL.h>

#include "../Singleton.h"

#include "../../DataModels/Vector2/Vector2.h"
#include "../../DataModels/Color/Color4.h"
#include "../../Utility/Event/Event.h"

class GAME_Camera2D;

class GAME_DisplayCore : public CORE_Singleton<GAME_DisplayCore> {
public:

	GAME_Camera2D* CurrentCamera = nullptr;

	SDL_Window* Window = nullptr;
	SDL_Renderer* Renderer = nullptr;

	color4 BackgroundColor = color4(125, 125, 125, 255);

	vector2 WindowSize;

	bool Fullscreen = false;

	GAME_Event<vector2> WindowResized;

private:

	GAME_DisplayCore() : CORE_Singleton("DisplayCore", 1) {}
	friend class CORE_Singleton<GAME_DisplayCore>;

	void ConfigureWindowSize();

public:

	bool HasPointInDisplay(vector2 position);

private:

	void _Init() override;
	void _Event(SDL_Event& event) override;
	void _Process(float delta) override;
	void _Exit() override;
};