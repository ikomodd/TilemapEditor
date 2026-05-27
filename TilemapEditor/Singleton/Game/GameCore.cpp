#include "GameCore.h"

#include "../Display/DisplayCore.h"
#include "../Origin/Scene/SceneCore.h"
#include "../Origin/Interface/InterfaceCore.h"

#include "../../Node/Origin/Origin.h"
#include "../../Node/Node.h"

#include "../../Node/Node2D/Node2D.h"
#include "../../Node/Frame2D/Frame2D.h"

void GAME_GameCore::_Init() {

	SDL_Init(SDL_INIT_VIDEO);
}

void GAME_GameCore::_Event(SDL_Event& event) {

	if (event.type == SDL_EVENT_QUIT)
		Running = false;

	auto FullInterfaceChildren = GAME_InterfaceCore::Get().CurrentOrigin->GetFullChildren();
	auto FullSceneChildren = GAME_SceneCore::Get().CurrentOrigin->GetFullChildren();

	std::vector<GAME_Node*> AllNodes = FullInterfaceChildren;
	AllNodes.insert(AllNodes.end(), FullSceneChildren.begin(), FullSceneChildren.end());

	for (GAME_Node* node : AllNodes) {



		node->_Event(event);
	}
}

void GAME_GameCore::_Process(float delta) {

	auto FullInterfaceChildren = GAME_InterfaceCore::Get().CurrentOrigin->GetFullChildren();
	auto FullSceneChildren = GAME_SceneCore::Get().CurrentOrigin->GetFullChildren();

	std::vector<GAME_Node*> AllNodes = FullInterfaceChildren;
	AllNodes.insert(AllNodes.end(), FullSceneChildren.begin(), FullSceneChildren.end());

	for (GAME_Node* node : AllNodes) {

		node->_Process(0);

		auto* Node2D = dynamic_cast<GAME_Transform*>(node);
		if (Node2D)
			Node2D->UpdateTransform();
	}
}

void GAME_GameCore::_Exit() {

	SDL_Quit();
}
