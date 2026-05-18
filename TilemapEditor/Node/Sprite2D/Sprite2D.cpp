#include "Sprite2D.h"

#include "../../Singleton/Display/DisplayCore.h"
#include "../Camera2D/Camera2D.h"

void GAME_Sprite2D::_Draw(SDL_Renderer* renderer) {

	auto* Camera = GAME_DisplayCore::Get().CurrentCamera;

	SDL_FRect ViewRect = {

		GlobalPosition.X + (Size.X * Offset.X),
		GlobalPosition.Y + (Size.Y * Offset.Y),
		Size.X,
		Size.Y,
	};
	ViewRect = Camera->InCameraView(ViewRect);

	if (Texture) {

		//renderiza aq
	}
	else {

		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		SDL_RenderFillRect(renderer, &ViewRect);
	}
}
