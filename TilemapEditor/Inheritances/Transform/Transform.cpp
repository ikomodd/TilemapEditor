#include "Transform.h"

#include "../../Node/Node2D/Node2D.h"

void GAME_Transform::UpdateLocalPosition() {

	auto* OwnerNode = static_cast<GAME_Node2D*>(this);
	auto* ParentTransform = dynamic_cast<GAME_Transform*>(OwnerNode->GetParent());

	if (ParentTransform)
		GlobalPosition = ParentTransform->GlobalPosition + LocalPosition;
	else
		GlobalPosition = LocalPosition;
}