#include "EditorScene.h"

#include "../../Node/Sprite2D/Sprite2D.h"
#include "../../Node/Camera2D/Camera2D.h"

void GAME_EditorScene::_Ready() {

	auto* Camera = new GAME_Camera2D("camera", vector2(0.f, 0.f), vector2(1.f, 1.f), vector2(0.f, 0.f));
	AddNode(Camera);

	auto* Sprite = new GAME_Sprite2D("sprite", vector2(0.f, 0.f), vector2(10.f, 10.f), vector2(-0.5f, -0.5f), "");
	AddNode(Sprite);

	auto* Sprite2 = new GAME_Sprite2D("sprite", vector2(10.f, 10.f), vector2(10.f, 10.f), vector2(-0.5f, -0.5f), "");
	Sprite->AddNode(Sprite2);
}