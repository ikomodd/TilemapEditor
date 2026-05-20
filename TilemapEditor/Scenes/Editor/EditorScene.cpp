#include "EditorScene.h"

#include "../../Node/Sprite2D/Sprite2D.h"
#include "../../Node/Camera2D/Camera2D.h"
#include "../../Actor/Tilemap/Tilemap.h"

void GAME_EditorScene::_Ready() {

	auto* Camera = new GAME_Camera2D("camera", vector2(0.f, 0.f), vector2(1.f, 1.f), vector2(0.f, 0.f));
	AddNode(Camera);

	auto* Tilemap = new GAME_Tilemap();
	AddNode(Tilemap);
}