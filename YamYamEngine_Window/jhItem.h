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

		virtual void Spawn(math::Vector2 position) = 0;
		
		virtual math::Vector2 GetSpawnPosition(Snake* snake) = 0;

		virtual void ApplyEffect(Snake* snake) = 0;

		virtual Item* OnEaten(Snake* snake) = 0;

		virtual eItemType GetItemType() = 0;
	private:
	};
}