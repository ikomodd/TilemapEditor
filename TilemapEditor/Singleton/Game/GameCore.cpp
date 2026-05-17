#include "GameCore.h"

#include "../Display/DisplayCore.h"
#include "../Scene/SceneCore.h"

#include "../../Node/Origin/Origin.h"
#include "../../Node/Node.h"
#include "../../Node/Node2D/Node2D.h"

void GAME_GameCore::_Init() {

	SDL_Init(SDL_INIT_VIDEO);
}

void GAME_GameCore::_Event(SDL_Event& event) {

	if (event.type == SDL_EVENT_QUIT)
		Running = false;
}

void GAME_GameCore::_Process(float delta) {

	auto FullChildren = GAME_SceneCore::Get().CurrentScene->GetFullChildren();
	for (GAME_Node* node : FullChildren) {

		node->_Process(0);
	}
}

void GAME_GameCore::_Exit() {

	SDL_Quit();
}
