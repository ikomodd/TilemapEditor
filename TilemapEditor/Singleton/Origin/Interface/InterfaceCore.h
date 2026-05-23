#pragma once

#include "../OriginCore.h"

class GAME_InterfaceCore : public GAME_OriginCore, public CORE_Singleton<GAME_InterfaceCore> {
private:

	GAME_InterfaceCore() : GAME_OriginCore(), CORE_Singleton("interface_core", 2) {}
	friend class CORE_Singleton;

	void _Process(float delta) {

		UpdateOrigin();
	}
};