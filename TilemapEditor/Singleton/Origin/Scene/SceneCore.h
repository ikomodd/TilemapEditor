#pragma once

#include "../OriginCore.h"

class GAME_SceneCore : public GAME_OriginCore, public CORE_Singleton<GAME_SceneCore> {
private:

	GAME_SceneCore() : GAME_OriginCore(), CORE_Singleton("scene_core", 2) {}
	friend class CORE_Singleton;

	void _Process(float delta) {

		UpdateOrigin();
	}
};