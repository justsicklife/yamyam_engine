#include "jhBackGround.h"
#include "jhTileMap.h"
#include <vector>
#include "jhTilemapRenderer.h"

namespace jh {
	void BackGround::Initialize()
	{

		TileMap* pTileMap = AddComponent<TileMap>();
		TilemapRenderer* pTilemapRenderer = AddComponent<TilemapRenderer>();

		pTilemapRenderer->SetTileSize(64);

		pTileMap->SetHeight(7);
		pTileMap->SetWidth(7);


		std::vector<int>& tileMap = pTileMap->GetTiles();
	
		tileMap.resize(pTileMap->GetHeight() * pTileMap->GetWidth());

		for (int i = 0; i < pTileMap->GetHeight(); i++) {
			for (int j = 0; j < pTileMap->GetWidth(); j++) {
				if ((j + i * pTileMap->GetWidth()) % 2 == 0) {
					tileMap[j+ i* pTileMap->GetWidth()] = 1;
				}
				else {
					tileMap[j + i * pTileMap->GetWidth()] = 0;
				}
			}
		}

	}
	void BackGround::Update()
	{
	}
	void BackGround::LateUpdate()
	{
	}
	void BackGround::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}