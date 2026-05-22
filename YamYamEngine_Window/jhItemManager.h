#pragma once
#include "..\\YamYamEngine_SOURCE\\\CommonInclude.h"
#include "..\\YamYamEngine_SOURCE\\\jhMath.h"
#include "jhItem.h"
#include <vector>

namespace jh {
	
	class ItemManager
	{
	public:

		void Initialize();
		void Update();
		void LateUpdate();
		void Render(HDC hdc);

		Item* FindItemAt(math::Vector2 position) {

			for (Item* item : mItems) {
				if (position == item->GetPosition()) {
					return item;
				}
			}

			return nullptr;
		}
		
		void AddItem(Item* item) {
			mItems.push_back(item);
		}

		void DeleteItem(Item* deleteItem) {
			for (int i = 0; i < mItems.size(); i++) {
				if (mItems[i] == deleteItem) {
					mItems.erase(mItems.begin() + i);
					break;
				}
			}
		}

	private:
		std::vector<Item*> mItems;
	};
}