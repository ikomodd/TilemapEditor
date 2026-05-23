#pragma once

#include "../Node.h"
#include "../../Inheritance/Transform/UiTransform/UiTransform.h"

class GAME_Frame2D : public GAME_Node, public GAME_UiTransform {
public:

	GAME_Frame2D(std::string name, vector2 position, vector2 size, vector2 anchor) : GAME_Node(name), GAME_UiTransform(position, size, anchor) {};
};