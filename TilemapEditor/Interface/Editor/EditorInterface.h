#pragma once

#include "../../Node/Origin/Origin.h"

class GAME_EditorInterface : public GAME_Origin {
public:

	GAME_EditorInterface() : GAME_Origin("editor_interface") {}

	void _Ready() override;
};