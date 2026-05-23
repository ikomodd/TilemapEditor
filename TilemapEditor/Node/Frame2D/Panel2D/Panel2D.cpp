#include "Panel2D.h"

void GAME_Panel2D::_Draw(SDL_Renderer* renderer) {

	SDL_FRect Rect = { GlobalPosition.X, GlobalPosition.Y, GlobalSize.X, GlobalSize.Y };

	if (!Texture) {
		SDL_SetRenderDrawColor(renderer, SolidColor.R, SolidColor.G, SolidColor.B, SolidColor.A);
		SDL_RenderFillRect(renderer, &Rect);
	}

	if (BorderColor.A > 0 && BorderSize > 0) {
		SDL_SetRenderDrawColor(renderer, BorderColor.R, BorderColor.G, BorderColor.B, BorderColor.A);

		SDL_FRect BorderRect = { Rect.x - 1.f, Rect.y - 1.f, Rect.w + 2.f, Rect.h + 2.f };

		for (float i = 0; i <= BorderSize; i++) {

			BorderRect = { BorderRect.x + 1.f, BorderRect.y + 1.0f, BorderRect.w - 2.f, BorderRect.h - 2.f };

			SDL_RenderRect(renderer, &BorderRect);
		}
	}
}
