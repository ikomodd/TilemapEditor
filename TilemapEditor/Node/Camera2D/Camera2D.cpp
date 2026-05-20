#include "Camera2D.h"

#include "../../Singleton/Display/DisplayCore.h"

#include "../Origin/Origin.h"

GAME_Camera2D::GAME_Camera2D(std::string name, vector2 position, vector2 size, vector2 offset) : GAME_Node2D(name, position, size, offset) {

	auto& Display = GAME_DisplayCore::Get();



	if (!Display.CurrentCamera)
		Display.CurrentCamera = this;
}

SDL_FRect GAME_Camera2D::InCameraView(SDL_FRect rect) {

	GAME_DisplayCore& Display = GAME_DisplayCore::Get();

	vector2 WindowCenter = Display.WindowSize / 2.f;
	vector2 OffsetPosition = GlobalPosition + Display.WindowSize * Offset;

	//vector2 ViewPosition = (node->GlobalPosition + (node->Size * node->Offset) - GlobalPosition)* Size + WindowCenter;
	//vector2 ViewSize = node->Size * Size;

	SDL_FRect Result = {

		(rect.x - OffsetPosition.X) * Size.X + WindowCenter.X,
		(rect.y - OffsetPosition.Y) * Size.Y + WindowCenter.Y,
		
		rect.h * Size.X,
		rect.h * Size.Y,
	};

	return Result;
}

vector2 GAME_Camera2D::InWorldSpace(vector2 position) {

	GAME_DisplayCore& Display = GAME_DisplayCore::Get();

	vector2 WindowCenter = Display.WindowSize / 2.f;
	vector2 OffsetPosition = GlobalPosition + Display.WindowSize * Offset;

	vector2 Result = (position + OffsetPosition) - WindowCenter;

	return Result;
}
