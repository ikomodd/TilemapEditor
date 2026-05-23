#include "EditorInterface.h"

#include "../../Node/Frame2D/Panel2D/Panel2D.h"

void GAME_EditorInterface::_Ready() {

	auto* UpperPanel = new GAME_Panel2D("upper_panel", "", 0, vector2(1.f, 0.05f), 0, 200, 150, 1.f);
	AddNode(UpperPanel);

	auto* LeftPanel = new GAME_Panel2D("left_panel", "", vector2(0.f, 0.05f), vector2(0.2f, 0.95f), vector2(0.f, 0.f), 200, 150, 1.f);
	AddNode(LeftPanel);

	auto* RightPanel = new GAME_Panel2D("right_panel", "", vector2(1.f, 0.05f), vector2(0.2f, 0.95f), vector2(-1.f, 0.f), 200, 150, 1.f);
	AddNode(RightPanel);


}