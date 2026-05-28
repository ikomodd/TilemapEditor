#include "EditorInterface.h"

#include "../../Node/Frame2D/Panel2D/Panel2D.h"
#include "../../Node/Frame2D/TextLabel2D/TextLabel2D.h"
#include "../../Node/Frame2D/Button2D/Button.h"
#include "../../Node/Frame2D/Container2D/Container2D.h"

#include "../../Actor/EditorContainer/EditorContainer.h"
#include "../../Actor/UpperContainer/UpperContainer.h"

void GAME_EditorInterface::_Ready() {

	auto* UpperContainer = new GAME_UpperContainer();
	AddNode(UpperContainer);

	auto* TilemapContainer = new GAME_EditorContainer("tilemap_container", "Tilemap", vector2(1.f, 0.04f), vector2(0.2f, 0.48f), vector2(-1.f, 0.f));
	AddNode(TilemapContainer);

	auto* PropertiesContainer = new GAME_EditorContainer("properties_container", "Properties", vector2(1.f, 0.5f), vector2(0.2f, 0.5f), vector2(-1.f, 0.f));
	AddNode(PropertiesContainer);
}
