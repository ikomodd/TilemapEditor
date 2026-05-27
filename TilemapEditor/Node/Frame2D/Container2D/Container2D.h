#pragma once

#include "../Panel2D/Panel2D.h"

class GAME_Container2D : public GAME_Panel2D {
private:

	void Ordenate();

public:

	vector2 Direction = vector2(0, 1.f);

	GAME_Container2D(std::string name, vector2 position, vector2 size, vector2 anchor, color4 solid_color = 200, color4 border_color = 150, float border_size = 1.f) : GAME_Panel2D(name, position, size, anchor, solid_color, border_color, border_size) {}

	void _Process(float delta) override;

	void _NodeAdded(GAME_Node* node) override;
	void _NodeRemoved(GAME_Node* node) override;
};