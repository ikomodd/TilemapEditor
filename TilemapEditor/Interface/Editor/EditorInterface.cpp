#include "EditorInterface.h"

#include "../../Node/Frame2D/Frame2D.h"

void GAME_EditorInterface::_Ready() {

	auto* Frame = new GAME_Frame2D("test_frame", 0, vector2(0.1f, 0.1f), 0);
	AddNode(Frame);

	auto* Frame2 = new GAME_Frame2D("test_frame2", vector2(1.f, 1.f), vector2(0.1f, 0.1f), vector2(-1.f, -1.f));
	AddNode(Frame2);

	auto* Frame3 = new GAME_Frame2D("test_frame3", 0, vector2(0.1f, 0.1f), vector2(-1.f, -1.f));
	Frame2->AddNode(Frame3);
}
