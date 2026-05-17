#include "SceneCore.h"

#include "../../Node/Origin/Origin.h"

void GAME_SceneCore::PlayScene(GAME_Origin* scene) {
	NextScene = scene;
}

void GAME_SceneCore::ForcePlayScene(GAME_Origin* scene) {

	if (CurrentScene)
		CurrentScene->Deinitialize();

	CurrentScene = scene;

	CurrentScene->_Ready();
	CurrentScene->Initialize();
}

void GAME_SceneCore::AddScene(GAME_Origin* scene) {

	if (HasScene(scene->Name))
		LoadedScenes.push_back(scene);
}

bool GAME_SceneCore::HasScene(std::string scene_name) {

	for (GAME_Origin* scene : LoadedScenes) {
		if (scene->Name == scene_name)
			return true;
	}
	return false;
}

//

void GAME_SceneCore::_Init() {

}

void GAME_SceneCore::_Process(float delta) {
	
	if (NextScene != nullptr) {

		if (CurrentScene)
			CurrentScene->Deinitialize();

		CurrentScene = NextScene;
		NextScene = nullptr;

		CurrentScene->_Ready();
		CurrentScene->Initialize();
	}
}

void GAME_SceneCore::_Exit() {

}
