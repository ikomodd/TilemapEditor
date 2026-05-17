#include "Origin.h"

void GAME_Origin::Initialize() {
	Initialized = true;

	for (GAME_Node* node : GetChildren()) {

		node->_Ready();
	}
}

void GAME_Origin::Deinitialize() {
	Initialized = false;

	//aqui tem que limpar o origin
}
