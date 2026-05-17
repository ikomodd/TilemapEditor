#pragma once

#include "../../Node/Origin/Origin.h"

class GAME_EditorScene : public GAME_Origin {
public:

	GAME_EditorScene() : GAME_Origin("editor") {}

	void _Ready() override;
};