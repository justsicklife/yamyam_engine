#pragma once
#include "jhComponent.h"
#include "CommonInclude.h"

namespace jh {
	// 타일맵에 크기와 타일에 요소를 담는 컴포넌트
	class TileMap : public Component
	{
	public :

		TileMap();
		~TileMap();

		void Initialize() override;
		void Update()  override;
		void LateUpdate()  override;
		void Render(HDC hdc)  override;
		
		int GetWidth() {
			return mWidth;
		}

		int GetHeight() {
			return mHeight;
		}

		void SetWidth(int width) {
			mWidth = width;
		}

		void SetHeight(int height) {
			mHeight = height;
		}
		
		void SetTileeSize(int tileSize) {
			mTileSize = tileSize;
		}

		int GetTileSize() {
			return mTileSize;
		}

		math::Vector2 GetOffset() {
			return mOffset;
		}

		void SetOffset(math::Vector2 offset) {
			mOffset = offset;
		}

		std::vector<int>& GetTiles() {
			return mTiles;
		}
			 
	private:
		int mWidth;
		int mHeight;
		int mTileSize;
		math::Vector2 mOffset;
		std::vector<int> mTiles;
	};
}