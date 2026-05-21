#pragma once
#include "..\\YamYamEngine_SOURCE\\\jhGameObject.h"
#include "..\\YamYamEngine_SOURCE\\\jhMath.h"
#include "jhGridPosition.h"

namespace jh {
	
	class Snake;

	enum class eItemType {
		Apple,
		Bomb
	};

	class Item : public GameObject,public GridPosition
	{
	public:

		virtual void ApplyEffect(Snake* snake) = 0;

		virtual void OnEaten(Snake* snake) = 0;

		virtual eItemType GetItemType() = 0;
	private:
	};
}