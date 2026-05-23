#pragma once

#include "../../DataModels/Vector2/Vector2.h"

class GAME_Transform {
public:

	GAME_Transform() {}
	virtual ~GAME_Transform() {}
	
	virtual void UpdateTransform() {};
};