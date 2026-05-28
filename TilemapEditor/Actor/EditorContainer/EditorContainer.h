#pragma once

#include "../../Node/Frame2D/Container2D/Container2D.h"
#include "../../Node/Frame2D/TextLabel2D/TextLabel2D.h"

class GAME_EditorContainer : public GAME_Container2D {
private:

	std::string Title;

public:

	GAME_EditorContainer(std::string name, std::string title, vector2 position, vector2 size, vector2 anchor) : Title(title), GAME_Container2D(name, position, size, anchor, 200, 150, 1) {}

	void _Ready() override{

		std::cout << "Hello\n";

		auto* TitleLabel = new GAME_TextLabel2D("title", "C:/Windows/Fonts/arial.ttf", 0.03f, 0, vector2(LocalSize.X, 0.04f), 0);
		TitleLabel->ChangeText(" " + Title, 40);
		AddNode(TitleLabel);
	}
};