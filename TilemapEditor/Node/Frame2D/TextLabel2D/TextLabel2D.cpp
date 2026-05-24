#include "TextLabel2D.h"

#include "../../../Singleton/Display/DisplayCore.h"

void GAME_TextLabel2D::_Ready() {

	GAME_DisplayCore::Get().WindowResized.Connect([this](vector2 window_size) {

		ChangeFont(FontPath, FontScale);
	});
}

void GAME_TextLabel2D::_Draw(SDL_Renderer* renderer) {

	GAME_Panel2D::_Draw(renderer);

	if (TextTexture) {

		SDL_FRect TextRect = {GlobalPosition.X, GlobalPosition.Y, TextSurface->w, TextSurface->h};

		SDL_RenderTexture(renderer, TextTexture, NULL, &TextRect);
	}
}
