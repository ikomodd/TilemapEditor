#pragma once

#include <map>

#include "../../Node/Node2D/Node2D.h"
#include "../../Inheritance/SpriteData/SpriteData.h"

#include "../../DataModels/Vector2/iVector2.h"

class GAME_Camera2D;

struct TILEMAP_Tile {
private:

	inline static unsigned int PrevId = 0;

public:

	unsigned int Id;
	vector2 SourcePosition;

	TILEMAP_Tile(vector2 source_position) : Id(PrevId++), SourcePosition(source_position) {}
};

class GAME_Tilemap : public GAME_Node, public GAME_SpriteData {
private:

	GAME_Camera2D* CurrentCamera;

	bool Drawing = false;
	bool Erasing = false;

	vector2 TileSize = vector2(32.f, 32.f);

	std::map<ivector2, unsigned int> Tilemap = {};
	std::map<ivector2, unsigned int> PreTilemap = {};

	std::vector<TILEMAP_Tile*> Tiles = {};

	TILEMAP_Tile* CurrentTile = nullptr;

public:

	GAME_Tilemap() : GAME_Node("tilemap"), GAME_SpriteData("") {}

	void CreateTile(vector2 source_position);

	void PreDrawTile(vector2 position);
	void DrawTiles();
	void EraseTile(vector2 position);

	void _Ready() override;
	void _Event(SDL_Event& event) override;
	void _Draw(SDL_Renderer* renderer) override;
	void _Process(float delta) override;
	void _Exit() override;
};