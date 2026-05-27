#include "EditorInterface.h"

#include "../../Node/Frame2D/Panel2D/Panel2D.h"
#include "../../Node/Frame2D/TextLabel2D/TextLabel2D.h"
#include "../../Node/Frame2D/Button2D/Button.h"

void GAME_EditorInterface::_Ready() {

	auto* UpperPanel = new GAME_Panel2D("upper_panel", "", 0, vector2(1.f, 0.05f), 0, 200, 150, 1.f);
	AddNode(UpperPanel);

	auto* ArchiveLabel = new GAME_Button2D("test_label", "C:/Windows/Fonts/arial.ttf", "", 0, vector2(0.1f, 0.05f), 0, 0.025f, 200, 150, 1.f);
	ArchiveLabel->ChangeText("Archive");
	UpperPanel->AddNode(ArchiveLabel);

	ArchiveLabel->OnClicked.Connect([]() {

		std::cout << "hai\n";
	});

	//

	auto* LeftPanel = new GAME_Panel2D("left_panel", "", vector2(0.f, 0.05f), vector2(0.2f, 0.95f), vector2(0.f, 0.f), 200, 150, 1.f);
	AddNode(LeftPanel);

	auto* TestLabel = new GAME_TextLabel2D("test_label", "C:/Windows/Fonts/arial.ttf", "", 0, vector2(0.2f, 0.04f), 0, 0.03f, 200, 150, 1.f);
	TestLabel->ChangeText(" Left Panel");
	LeftPanel->AddNode(TestLabel);

	auto* RightPanel = new GAME_Panel2D("right_panel", "", vector2(1.f, 0.05f), vector2(0.2f, 0.95f), vector2(-1.f, 0.f), 200, 150, 1.f);
	AddNode(RightPanel);
}
