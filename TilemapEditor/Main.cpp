#include "Singleton/Game/GameCore.h"
#include "Singleton/Display/DisplayCore.h"
#include "Singleton/Scene/SceneCore.h"

#include "Scenes/Editor/EditorScene.h"

int main() {

	auto& Game = GAME_GameCore::Get();
	auto& Scenes = GAME_SceneCore::Get();
	GAME_DisplayCore::Get();

	CORE_iSingleton::InitAll();

	auto* Editor = new GAME_EditorScene();
	Scenes.AddScene(Editor);
	Scenes.ForcePlayScene(Editor);

	while (Game.Running) {
		while (SDL_PollEvent(&Game.Event)) {

			CORE_iSingleton::EventAll(Game.Event);
		}

		CORE_iSingleton::ProcessAll(0); // TA SEM CALCULAR DELTA
	}
	CORE_iSingleton::ExitAll();

	return 1;
}