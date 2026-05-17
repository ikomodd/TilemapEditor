#pragma once

#include "../Node.h"

class GAME_Origin : public GAME_Node {
public:

	bool Initialized = false;

	GAME_Origin(std::string name) : GAME_Node(name) {}

	void Initialize();
	void Deinitialize();
};