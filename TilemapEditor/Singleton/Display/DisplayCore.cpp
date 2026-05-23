#include "DisplayCore.h"

#include "../Origin/Scene/SceneCore.h"
#include "../Origin/Interface/InterfaceCore.h"

#include "../../Node/Node.h"
#include "../../Node/Origin/Origin.h"

#include "../../DataModels/Vector2/iVector2.h"

void GAME_DisplayCore::ConfigureWindowSize() {

	ivector2 iWindowSize;
	SDL_GetWindowSize(Window, &iWindowSize.X, &iWindowSize.Y);
	WindowSize = iWindowSize.ToVector2();
}

//

void GAME_DisplayCore::_Init() {

	Window = SDL_CreateWindow("TilemapEditor", 800, 600, SDL_WINDOW_RESIZABLE);
	Renderer = SDL_CreateRenderer(Window, 0);

	ConfigureWindowSize();
}

void GAME_DisplayCore::_Event(SDL_Event& event) {

	if (event.type == SDL_EVENT_WINDOW_RESIZED)
		ConfigureWindowSize();
}

void GAME_DisplayCore::_Process(float delta) {

	SDL_SetRenderDrawColor(Renderer, BackgroundColor.R, BackgroundColor.G, BackgroundColor.B, 255);
	SDL_RenderClear(Renderer);

	auto FullInterfaceChildren = GAME_InterfaceCore::Get().CurrentOrigin->GetFullChildren();
	auto FullSceneChildren = GAME_SceneCore::Get().CurrentOrigin->GetFullChildren();

	std::vector<GAME_Node*> AllNodes = FullInterfaceChildren;
	AllNodes.insert(AllNodes.end(), FullSceneChildren.begin(), FullSceneChildren.end());

	for (GAME_Node* node : AllNodes) {

		node->_Draw(Renderer);
	}

	SDL_RenderPresent(Renderer);
}

void GAME_DisplayCore::_Exit() {
}
