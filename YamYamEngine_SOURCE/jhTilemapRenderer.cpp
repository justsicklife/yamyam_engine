#include "jhTilemapRenderer.h"
#include "jhTileMap.h"
#include "jhTransform.h"

namespace jh {
	TilemapRenderer::TilemapRenderer()
	{
	}
	TilemapRenderer::~TilemapRenderer()
	{
	}
	void TilemapRenderer::Initialize()
	{

	}

	void TilemapRenderer::Update()
	{
	}

	void TilemapRenderer::LateUpdate()
	{
	}

	void TilemapRenderer::Render(HDC hdc)
	{
		TileMap* tileMap = GetOwner()->GetComponent<TileMap>();

		Transform * transform =GetOwner()->GetComponent<Transform>();

		if (tileMap == nullptr) {
			return;
		}

		std::vector<int>& tiles = tileMap->GetTiles();

		int width = tileMap->GetWidth();
		int height = tileMap->GetHeight();

		for (int y = 0; y < height; y++) {
			for (int x = 0; x < width; x++) {
				int index = x + y * width;
				int tile = tiles[index];

				int drawX = x * mTileSize + transform->GetPosition().x;
				int drawY = y * mTileSize + transform->GetPosition().y;

				if (tile == 1) {
					
					HBRUSH brush = CreateSolidBrush(RGB(255, 0, 0)); // »¡°­
					HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush);

					Rectangle(hdc,
						drawX,
						drawY,
						drawX + mTileSize,
						drawY + mTileSize
					);

					SelectObject(hdc, oldBrush);
					DeleteObject(brush);
				}
				else if(tile == 0) {
					HBRUSH brush = CreateSolidBrush(RGB(0, 0, 255)); // ÆÄ¶û
					HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush);

					Rectangle(hdc,
						drawX,
						drawY,
						drawX + mTileSize,
						drawY + mTileSize
					);

					SelectObject(hdc, oldBrush);
					DeleteObject(brush);
				}
			}
		}

	}
}