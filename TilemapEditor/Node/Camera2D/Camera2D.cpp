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

	vector2 Result = (position - WindowCenter) / Size + OffsetPosition;

	return Result;
}

void GAME_Camera2D::_Event(SDL_Event& event) {

	if (event.button.button == SDL_BUTTON_MIDDLE) {
		if (event.type == SDL_EVENT_MOUSE_BUTTON_DOWN) {

			PrevMousePosition = vector2(event.button.x, event.button.y);

			Moving = true;
		}
		else if (event.type == SDL_EVENT_MOUSE_BUTTON_UP) {

			Moving = false;
		}
	}
	if (event.type == SDL_EVENT_MOUSE_MOTION && Moving) {
		
		vector2 CurrentMousePosition = vector2(event.motion.x, event.motion.y);
		vector2 MouseDelta = (CurrentMousePosition - PrevMousePosition) / Size;

		PrevMousePosition = CurrentMousePosition;

		LocalPosition -= MouseDelta;

		std::cout << GlobalPosition.ToString() << "\n";
	}
	if (event.type == SDL_EVENT_MOUSE_WHEEL) {
		
		float Direction = event.wheel.y * 0.1f;

		Size += vector2(Direction, Direction);
		Size = Size.Clamp(vector2(0.1f, 0.1f), vector2(5.0f, 5.0f));
	}
}
