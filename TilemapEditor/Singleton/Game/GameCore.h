#pragma once

#include "../Singleton.h"

class GAME_GameCore : public CORE_Singleton<GAME_GameCore> {
public:

	SDL_Event Event = {};

	bool Running = true;
	
private:

	GAME_GameCore() : CORE_Singleton("GameCore", 0) {}
	friend class CORE_Singleton<GAME_GameCore>;

	void _Init() override;
	void _Event(SDL_Event& event) override;
	void _Process(float delta) override;
	void _Exit() override;
};