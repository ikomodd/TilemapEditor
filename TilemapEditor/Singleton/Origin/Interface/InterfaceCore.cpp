#include "InterfaceCore.h"

#include "../../../Node/Origin/Origin.h"
#include "../../../Node/Frame2D/Frame2D.h"

bool GAME_InterfaceCore::HasUiInPoint(vector2 position) {

	for (GAME_Node* node : CurrentOrigin->GetFullChildren()) {

		auto* Frame2D = static_cast<GAME_Frame2D*>(node);

		if (Frame2D->HasCollision(position) && Frame2D->StopMouse)
			return true;
	}
	return false;
}
