#pragma once
#include "jhItem.h"

namespace jh {
	class Apple : public Item
	{
	public :
		
		Item* OnEaten(Snake* snake) override;
		void ApplyEffect(Snake* snake) override;

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		eItemType GetItemType() override;

		math::Vector2 GetSpawnPosition(Snake* snake) override;

		void Spawn(math::Vector2 position);

	private :

	};
}