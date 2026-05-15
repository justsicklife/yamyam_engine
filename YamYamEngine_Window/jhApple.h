#pragma once
#include "jhItem.h"

namespace jh {
	class Apple : public Item
	{
	public :
		
		void OnEaten(Snake* snake) override;

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		eItemType GetItemType() override;


	private :

	};
}