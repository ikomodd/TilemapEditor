#include "WorldTransform.h"

#include "../../../Node/Node2D/Node2D.h"

void GAME_WorldTransform::UpdateTransform() {

	auto* OwnerNode = static_cast<GAME_Node2D*>(this);
	auto* ParentTransform = dynamic_cast<GAME_WorldTransform*>(OwnerNode->GetParent());

	if (ParentTransform)
		GlobalPosition = ParentTransform->GlobalPosition + LocalPosition;
	else
		GlobalPosition = LocalPosition;
}