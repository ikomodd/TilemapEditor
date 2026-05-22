#include "Tilemap.h"

#include "../../Singleton/Display/DisplayCore.h"
#include "../../Node/Camera2D/Camera2D.h"

// OBS: Os std::cout's causam queda de FPS, usa só pra debug e comenta eles no final

void GAME_Tilemap::CreateTile(vector2 source_position) {

	auto* Tile = new TILEMAP_Tile(source_position);
	Tiles.push_back(Tile);
}

void GAME_Tilemap::DrawLine(vector2 from, vector2 to) {

	vector2 ToWorldPosition = CurrentCamera->InWorldSpace(to);
	vector2 ToGridPosition = (ToWorldPosition / TileSize);

	vector2 FromWorldPosition = CurrentCamera->InWorldSpace(from);
	vector2 FromGridPosition = (FromWorldPosition / TileSize);

	vector2 Delta = ToGridPosition - FromGridPosition;
	float Distance = sqrt(Delta.X * Delta.X + Delta.Y * Delta.Y);

	int Steps = (int)Distance + 1;

	for (int i = 0; i <= Steps; i++) {

		float t = (float)i / Steps;
		vector2 Pos = FromGridPosition + Delta * t;
		
		DrawTile(Pos.ToiVector2());
	}
}

void GAME_Tilemap::DrawTile(ivector2 position) {

	PreTilemap[position] = CurrentTileId;

	//std::cout << "PreDraw: " << PreTilemap.size() << "\n";
}

void GAME_Tilemap::InsertTiles() {

	for (auto it = PreTilemap.begin(); it != PreTilemap.end(); it++) {

		if (Drawing)
			Tilemap[it->first] = it->second;

		if (Erasing) {

			for (auto it2 = Tilemap.begin(); it2 != Tilemap.end(); ) {

				if (it2->first == it->first)

					it2 = Tilemap.erase(it2);
				else
					++it2;
			}
		};
	}
	PreTilemap.clear();

	std::cout << "Draw: " << Tilemap.size() << "\n";
}

//

void GAME_Tilemap::_Ready() {

	CurrentCamera = GAME_DisplayCore::Get().CurrentCamera;
}

void GAME_Tilemap::_Event(SDL_Event& event) {

	if (event.type == SDL_EVENT_MOUSE_BUTTON_DOWN) {

		vector2 MousePosition = vector2(event.button.x, event.button.y);
		PrevMousePosition = MousePosition;

		if (event.button.button == SDL_BUTTON_LEFT) {

			DrawLine(PrevMousePosition, MousePosition);
			Drawing = true;
		}

		else if (event.button.button == SDL_BUTTON_RIGHT) {

			if (PreTilemap.size() > 0) {
				PreTilemap.clear();

				Drawing = false;
			}
			else {

				DrawLine(PrevMousePosition, MousePosition);
				Erasing = true;
			}
		}
	}

	else if (event.type == SDL_EVENT_MOUSE_BUTTON_UP) {
		
		if (PreTilemap.size() > 0)
			InsertTiles();

		Drawing = false;
		Erasing = false;
	}
	else if (event.type == SDL_EVENT_MOUSE_MOTION) {

		vector2 MousePosition = vector2(event.button.x, event.button.y);

		if (Drawing || Erasing)
			DrawLine(PrevMousePosition, MousePosition);

		PrevMousePosition = MousePosition;
	}
}

void GAME_Tilemap::_Draw(SDL_Renderer* renderer) {

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

	auto* Camera = GAME_DisplayCore::Get().CurrentCamera;

	std::map <ivector2, unsigned int> AllTiles = Tilemap;
	for (auto current_tile : PreTilemap)
		AllTiles[current_tile.first] = current_tile.second;

	for (auto current_tile : AllTiles) {

		SDL_FRect TileRect = { current_tile.first.X * TileSize.X, current_tile.first.Y * TileSize.Y, TileSize.X, TileSize.Y };

		TileRect = Camera->InCameraView(TileRect);

		SDL_RenderFillRect(renderer, &TileRect);
	}
}

void GAME_Tilemap::_Process(float delta) {

}

void GAME_Tilemap::_Exit() {

}
