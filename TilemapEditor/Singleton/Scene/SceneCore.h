#pragma once

#include "../Singleton.h"

class GAME_Origin;

class GAME_SceneCore : public CORE_Singleton<GAME_SceneCore> {
private:

	std::vector <GAME_Origin*> LoadedScenes = {};

	GAME_Origin* NextScene = nullptr;

public:

	GAME_Origin* CurrentScene = nullptr;

	void PlayScene(GAME_Origin* scene);
	void ForcePlayScene(GAME_Origin* scene);

	void AddScene(GAME_Origin* scene);

	bool HasScene(std::string scene_name);

private:

	GAME_SceneCore() : CORE_Singleton("World2DCore", 2) {}
	friend class CORE_Singleton<GAME_SceneCore>;

	void _Init() override;
	void _Process(float delta) override;
	void _Exit() override;
};