#include "UpperContainer.h"

#include "../../Singleton/Display/DisplayCore.h"
#include "../ContextContainer/ContextContainer.h"

GAME_ContextContainer* GAME_UpperContainer::CreateContext(SDL_Event& event) {

	auto& Display = GAME_DisplayCore::Get();

	vector2 LocalClick = vector2(event.button.x, event.button.y) / Display.WindowSize;

	auto* ContextContainer = new GAME_ContextContainer(LocalClick);
	GetParent()->AddNode(ContextContainer);

	return ContextContainer;
}

void GAME_UpperContainer::_Ready() {

	auto* ArchiveButton = new GAME_Button2D("archive_button", "C:/Windows/Fonts/arial.ttf", 0.03f, 0, vector2(0.09f, 0.04f), 0, 200, 125, 1.f);
	ArchiveButton->ChangeText("Archive", 40);
	AddNode(ArchiveButton);

	ArchiveButton->OnClicked.Connect([this](SDL_Event& event) {

		SetupArchiveButton(event);
	});

	auto* EditorButton = new GAME_Button2D("archive_button", "C:/Windows/Fonts/arial.ttf", 0.03f, 0, vector2(0.09f, 0.04f), 0, 200, 125, 1.f);
	EditorButton->ChangeText("Editor", 40);
	AddNode(EditorButton);

	auto* TilemapButton = new GAME_Button2D("archive_button", "C:/Windows/Fonts/arial.ttf", 0.03f, 0, vector2(0.09f, 0.04f), 0, 200, 125, 1.f);
	TilemapButton->ChangeText("Tilemap", 40);
	AddNode(TilemapButton);

	auto* PropertiesButton = new GAME_Button2D("archive_button", "C:/Windows/Fonts/arial.ttf", 0.03f, 0, vector2(0.09f, 0.04f), 0, 200, 125, 1.f);
	PropertiesButton->ChangeText("Proper.", 40);
	AddNode(PropertiesButton);

	auto* ViewButton = new GAME_Button2D("archive_button", "C:/Windows/Fonts/arial.ttf", 0.03f, 0, vector2(0.09f, 0.04f), 0, 200, 125, 1.f);
	ViewButton->ChangeText("View", 40);
	AddNode(ViewButton);
}
