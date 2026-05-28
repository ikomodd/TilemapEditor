#pragma once

#include "../../Node/Frame2D/Container2D/Container2D.h"
#include "../../Node/Frame2D/Button2D/Button.h"

class GAME_UpperContainer : public GAME_Container2D {
public:

	GAME_UpperContainer() : GAME_Container2D("upper_container", 0, vector2(1, 0.04), 0, 150, 125, 1.f) {
		Direction = vector2(1.f, 0.f);
	}

	void _Ready() override {

		auto* ArchiveButton = new GAME_Button2D("archive_button", "C:/Windows/Fonts/arial.ttf", 0.03f, 0, vector2(0.09f, 0.04f), 0, 200, 125, 1.f);
		ArchiveButton->ChangeText("Archive", 40);
		AddNode(ArchiveButton);

		auto* EditorButton = new GAME_Button2D("archive_button", "C:/Windows/Fonts/arial.ttf", 0.03f, 0, vector2(0.09f, 0.04f), 0, 200, 125, 1.f);
		EditorButton->ChangeText("Editor", 40);
		AddNode(EditorButton);

		auto* TilemapButton = new GAME_Button2D("archive_button", "C:/Windows/Fonts/arial.ttf", 0.03f, 0, vector2(0.09f, 0.04f), 0, 200, 125, 1.f);
		TilemapButton->ChangeText("Tilemap.", 40);
		AddNode(TilemapButton);

		auto* PropertiesButton = new GAME_Button2D("archive_button", "C:/Windows/Fonts/arial.ttf", 0.03f, 0, vector2(0.09f, 0.04f), 0, 200, 125, 1.f);
		PropertiesButton->ChangeText("Proper.", 40);
		AddNode(PropertiesButton);

		auto* ViewButton = new GAME_Button2D("archive_button", "C:/Windows/Fonts/arial.ttf", 0.03f, 0, vector2(0.09f, 0.04f), 0, 200, 125, 1.f);
		ViewButton->ChangeText("View", 40);
		AddNode(ViewButton);
	}
};