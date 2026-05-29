#include "UpperContainer.h"

#include "../ContextContainer/ContextContainer.h"

void GAME_UpperContainer::SetupArchiveButton(SDL_Event& event) {

	auto* ContextMenu = CreateContext(event);

	auto* SaveButton = ContextMenu->AddButton("Save");
	auto* ExportButton = ContextMenu->AddButton("Export");
	auto* ImportButton = ContextMenu->AddButton("Import");
}