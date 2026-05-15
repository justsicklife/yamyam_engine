#pragma once
#include "..\\YamYamEngine_SOURCE\\\jhGameObject.h"
#include "..\\YamYamEngine_SOURCE\\\jhMath.h"
#include "..\\YamYamEngine_SOURCE\\\jhLinkedList.h"
#include "..\\YamYamEngine_SOURCE\\\jhTileMap.h"
#include "..\\YamYamEngine_SOURCE\\\jhTilemapRenderer.h"

#include "jhSnakeHead.h"
#include "jhSnakeBody.h"

namespace jh {

	enum class Direction {
		Up,
		Right,
		Down,
		Left,
		None
	};

	class Snake
	{
	public:
		void Initialize();
		void Update();
		void LateUpdate();
		void Render(HDC hdc);

		bool Step(math::Vector2& prevPos);

		void UpdateBodyPositions(math::Vector2 stepPos);

		bool IsOutOfBounds(math::Vector2 nextPos);

		void SetTileMap(TileMap* tileMap) {
			mTileMap = tileMap;
		}

		TileMap* GetTileMap() {
			return mTileMap;
		}

		void Grow();

	private:
		Direction dir;
		SnakeHead* head;
		LinkedList<SnakeBody*> bodies;
		TileMap* mTileMap;
		float currentTIme;
	};
}