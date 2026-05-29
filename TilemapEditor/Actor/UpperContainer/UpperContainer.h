#pragma once

#include "../../Node/Frame2D/Container2D/Container2D.h"
#include "../../Node/Frame2D/Button2D/Button.h"

class GAME_ContextContainer;

class GAME_UpperContainer : public GAME_Container2D {
public:

	GAME_UpperContainer() : GAME_Container2D("upper_container", 0, vector2(1, 0.04), 0, 150, 125, 1.f) {
		Direction = vector2(1.f, 0.f);
	}

	GAME_ContextContainer* CreateContext(SDL_Event& event);

	void SetupArchiveButton(SDL_Event& event);

	void _Ready() override;
};