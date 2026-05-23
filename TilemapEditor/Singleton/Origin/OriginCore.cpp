#include "OriginCore.h"

#include "../../Node/Origin/Origin.h"

void GAME_OriginCore::Play(GAME_Origin* origin) {

	NextOrigin = origin;
}

void GAME_OriginCore::ForcePlay(GAME_Origin* origin) {

	CurrentOrigin = origin;

	CurrentOrigin->_Ready();
	CurrentOrigin->Initialize();
}

void GAME_OriginCore::Add(GAME_Origin* origin) {

	if (Has(origin->Name)) {

		LoadedOrigins[origin->Name] = origin;
	}
}

bool GAME_OriginCore::Has(std::string origin_name) {

	if (LoadedOrigins.contains(origin_name))
		return true;
	else
		return false;
}

//

void GAME_OriginCore::UpdateOrigin() {

	if (NextOrigin) {

		CurrentOrigin = nullptr;

		CurrentOrigin = NextOrigin;
		NextOrigin = nullptr;

		CurrentOrigin->_Ready();
		CurrentOrigin->Initialize();
	}
}