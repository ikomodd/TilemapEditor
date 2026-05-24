#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>

#include "Singleton/Game/GameCore.h"
#include "Singleton/Display/DisplayCore.h"

#include "Singleton/Origin/Scene/SceneCore.h"
#include "Singleton/Origin/Interface/InterfaceCore.h"

#include "Singleton/Asset/AssetCore.h"

#include "Scenes/Editor/EditorScene.h"
#include "Interface/Editor/EditorInterface.h"

int main() {

	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();

	auto& Game = GAME_GameCore::Get();
	auto& Scenes = GAME_SceneCore::Get();
	auto& Interface = GAME_InterfaceCore::Get();
	GAME_DisplayCore::Get();
	GAME_AssetCore::Get();

	CORE_iSingleton::InitAll();

	auto* EditorScene = new GAME_EditorScene();
	Scenes.Add(EditorScene);
	Scenes.ForcePlay(EditorScene);

	auto* EditorInterface = new GAME_EditorInterface();
	Interface.Add(EditorInterface);
	Interface.ForcePlay(EditorInterface);

	while (Game.Running) {
		while (SDL_PollEvent(&Game.Event)) {

			CORE_iSingleton::EventAll(Game.Event);
		}

		CORE_iSingleton::ProcessAll(0); // TA SEM CALCULAR DELTA
	}
	CORE_iSingleton::ExitAll();

	return 1;
}