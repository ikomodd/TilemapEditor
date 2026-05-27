#include "Button.h"

void GAME_Button2D::_Event(SDL_Event& event) {

	bool State = HasCollision(vector2(event.button.x, event.button.y));
	
	if (event.type == SDL_EVENT_MOUSE_BUTTON_DOWN && State) {

		SolidColor -= 40;
	}

	else if (event.type == SDL_EVENT_MOUSE_BUTTON_UP && State) {

		SolidColor += 40;

		_Clicked();
		OnClicked.Invoke();
	}

	else if (event.type == SDL_EVENT_MOUSE_MOTION) {
		if (State && !Floating) { // entrou

			SolidColor -= 40;
			Floating = true;
		}
		else if (!State && Floating) {

			SolidColor += 40;
			Floating = false;
		}
	}
}
