#pragma once
#include "..\\YamYamEngine_SOURCE\\\jhGameObject.h"
#include "..\\YamYamEngine_SOURCE\\\jhMath.h"
#include "jhSnake.h"
#include "jhGridPosition.h"

namespace jh {

	enum class eItemType {
		Apple,
		Bomb
	};

	class Item : public GameObject,public GridPosition
	{
	public:

		virtual void OnEaten(Snake* snake) = 0;

		virtual eItemType GetItemType() = 0;

		void SetSnake(Snake* snake) {
			this->snake = snake;
		}

		Snake* GetSnake() {
			return snake;
		}

		bool isColliding;
	private:
		Snake* snake;
	};
}