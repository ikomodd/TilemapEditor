#include "EditorInterface.h"

#include "../../Node/Frame2D/Panel2D/Panel2D.h"
#include "../../Node/Frame2D/TextLabel2D/TextLabel2D.h"
#include "../../Node/Frame2D/Button2D/Button.h"
#include "../../Node/Frame2D/Container2D/Container2D.h"

void GAME_EditorInterface::_Ready() {

	auto* Container = new GAME_Container2D("container", 0, vector2(0.2f, 1.f), 0);
	AddNode(Container);

	auto* Frame1 = new GAME_Panel2D("frame", 0, vector2(0.2f, 0.2f), 0);
	Container->AddNode(Frame1);

	auto* Frame2 = new GAME_Panel2D("frame", 0, vector2(0.2f, 0.1f), 0);
	Container->AddNode(Frame2);
}
