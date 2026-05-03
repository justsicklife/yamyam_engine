#pragma once
#include "..\\YamYamEngine_SOURCE\\jhGameObject.h"

namespace jh {
	
	enum class TileType {
		None,
		Apple,
		Snake
	};

	class Tile : public GameObject
	{
	public:
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		TileType GetTileType() {
			return tileType;
		}

		void SetTileType(TileType tileType) {
			tileType = tileType;
		}

	private:
		TileType tileType;
	};
}