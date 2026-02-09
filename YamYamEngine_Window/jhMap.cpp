#include "jhMap.h"

namespace jh {
	Map::Map() : 
		TileSize(24),
		width(5),
		height(5)
	{
		Initialize();
	}

	void Map::Initialize() {

		mapArray = vector<vector<ObjectType>>(
			height,
			vector<ObjectType>(width, ObjectType::Baba)
		);

	}

	void Map::Update() {

	}
	
	void Map::LateUpdate()
	{
		GameObject::LateUpdate();
	}

	void Map::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
		
}