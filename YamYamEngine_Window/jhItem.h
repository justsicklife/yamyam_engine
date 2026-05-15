#pragma once
#include "..\\YamYamEngine_SOURCE\\\jhGameObject.h"
#include "..\\YamYamEngine_SOURCE\\\jhMath.h"
#include "jhSnake.h"

namespace jh {

	enum class eItemType {
		Apple,
		Bomb
	};

	class Item : public GameObject
	{
	public:

		virtual void OnEaten(Snake* snake) = 0;

		virtual eItemType GetItemType() = 0;

		void SetPosition(math::Vector2 position) {
			mPosition = position;
		}

		math::Vector2 GetPosition() {
			return mPosition;
		}

	private:

		math::Vector2 mPosition;
	};
}