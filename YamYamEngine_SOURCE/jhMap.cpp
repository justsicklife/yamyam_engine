#include "jhMap.h"

namespace jh {

	Object** Map::Tiles = nullptr;

	void Map::Initailize() {
		Map::Tiles = new Object * [5];

		for (int i = 0; i < 5; i++) {
			Map::Tiles[i] = new Object[5];
		}

		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				Map::Tiles[i][j] = Object::None;
			}
		}
		
		Map::Tiles[0][3] = Object::Player;
	}

	void Map::Update() {

	}
}