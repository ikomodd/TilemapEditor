#pragma once

#include "../../Node/Frame2D/Container2D/Container2D.h"
#include "../../Node/Frame2D/Button2D/Button.h"

class GAME_ContextContainer : public GAME_Container2D {
public:

	GAME_ContextContainer(vector2 position) : GAME_Container2D("container", position, vector2(0.2f, 0.f), 0, color4(0, 0, 0, 0), 0, 0.f) {}

	GAME_Button2D* AddButton(std::string name) {

		auto* Button = new GAME_Button2D(name, "C:/Windows/Fonts/arial.ttf", 0.03f, 0, vector2(0.15f, 0.04f), 0, 200, 170, 1.f);
		Button->HorizontalAlign = GAME_Button2D::HORIZONTAL_ALIGN_LEFT;
		Button->ChangeText(" " + name, 40);
		AddNode(Button);

		return Button;
	}

	void _Event(SDL_Event& event) override {

		if (event.type == SDL_EVENT_MOUSE_BUTTON_UP) {

			std::cout << "Destroi aki\n";
		}
	}
};