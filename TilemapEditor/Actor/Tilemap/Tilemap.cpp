#include "Tilemap.h"

#include "../../Singleton/Display/DisplayCore.h"
#include "../../Node/Camera2D/Camera2D.h"

void GAME_Tilemap::CreateTile(vector2 source_position) {

	auto* Tile = new TILEMAP_Tile(source_position);
	Tiles.push_back(Tile);
}

void GAME_Tilemap::PreDrawTile(vector2 position) {

	vector2 WorldPosition = CurrentCamera->InWorldSpace(position);
	ivector2 GridPosition = (WorldPosition / TileSize).ToiVector2();

	PreTilemap[GridPosition] = 0; // 0 só pra debug, o certo é CurrentTilemap->Id

	std::cout << "PreDraw: " << PreTilemap.size() << "\n";
}

void GAME_Tilemap::DrawTiles() {

	for (auto current_tile : PreTilemap) {

		Tilemap[current_tile.first] = current_tile.second;
	}
	PreTilemap.clear();

	std::cout << "Draw: " << Tilemap.size() << "\n";
}

void GAME_Tilemap::EraseTile(vector2 position) {

	vector2 WorldPosition = CurrentCamera->InWorldSpace(position);
	ivector2 GridPosition = (WorldPosition / TileSize).ToiVector2();

	if (Tilemap.contains(GridPosition)) {

		for (auto it = Tilemap.begin(); it != Tilemap.end(); ) {

			if (it->first == GridPosition) {
				Tilemap.erase(it);
				break;
			}
			else
				it++;
		}
	}

	std::cout << "Erase: " << Tilemap.size() << "\n";
}

//

void GAME_Tilemap::_Ready() {

	CurrentCamera = GAME_DisplayCore::Get().CurrentCamera;
}

void GAME_Tilemap::_Event(SDL_Event& event) {

	if (event.type == SDL_EVENT_MOUSE_BUTTON_DOWN) {

		if (event.button.button == SDL_BUTTON_LEFT) {
			PreDrawTile(vector2(event.button.x, event.button.y));
			Drawing = true;
		}
		else if (event.button.button == SDL_BUTTON_RIGHT) {

			if (PreTilemap.size() > 0) {
				PreTilemap.clear();

				Drawing = false;
			}
			else {
				EraseTile(vector2(event.button.x, event.button.y));
				Erasing = true;
			}
		}

	}
	else if (event.type == SDL_EVENT_MOUSE_BUTTON_UP) {
		
		if (PreTilemap.size() > 0)
			DrawTiles();

		Drawing = false;
		Erasing = false;
	}
	else if (event.type == SDL_EVENT_MOUSE_MOTION) {
		if (Drawing == true)
			PreDrawTile(vector2(event.motion.x, event.motion.y));
		else if (Erasing == true)
			EraseTile(vector2(event.motion.x, event.motion.y));
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
