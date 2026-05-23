#pragma once

#include <map>
#include "../Singleton.h"

class GAME_Origin;

class GAME_OriginCore {
private:

	// isso seria mais util pra permanencia de estado da cena, não sei exatamente se é util aqui
	std::map <std::string, GAME_Origin*> LoadedOrigins = {};

	GAME_Origin* NextOrigin = nullptr;

public:

	GAME_Origin* CurrentOrigin = nullptr;

	void Play(GAME_Origin* origin);
	void ForcePlay(GAME_Origin* origin);

	void Add(GAME_Origin* origin);

	bool Has(std::string origin_name);

protected:

	GAME_OriginCore() {}

	void UpdateOrigin();
};