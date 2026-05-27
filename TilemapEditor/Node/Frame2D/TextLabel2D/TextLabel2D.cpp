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

		SDL_FRect TextRect = {GlobalPosition.X, GlobalPosition.Y, (float)TextSurface->w, (float)TextSurface->h};

		switch (VerticalAlign)
		{
		case GAME_TextData::VERTICAL_ALIGN_TOP: // padrão
			break;
		case GAME_TextData::VERTICAL_ALIGN_CENTER: TextRect.y += GlobalSize.Y / 2 - (TextRect.h / 2);
			break;
		case GAME_TextData::VERTICAL_ALIGN_BOTTOM: TextRect.y += GlobalSize.Y - TextRect.h;
			break;
		}

		switch (HorizontalAlign)
		{
		case GAME_TextData::HORIZONTAL_ALIGN_LEFT: // padrão
			break;
		case GAME_TextData::HORIZONTAL_ALIGN_CENTER: TextRect.x += GlobalSize.X / 2 - (TextRect.w / 2);
			break;
		case GAME_TextData::HORIZONTAL_ALIGN_RIGHT: TextRect.x += GlobalSize.X - TextRect.w;
			break;
		}

		SDL_RenderTexture(renderer, TextTexture, NULL, &TextRect);
	}
}
