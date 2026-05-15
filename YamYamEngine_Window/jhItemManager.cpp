#include "jhItemManager.h"

namespace jh {

	void ItemManager::Initialize()
	{
	}
	
	void ItemManager::Update()
	{
	}
	
	void ItemManager::LateUpdate()
	{
		for (Item* item : mItems) {
			item->LateUpdate();
		}
	}
	
	void ItemManager::Render(HDC hdc)
	{
		for (Item* item : mItems) {
			item->Render(hdc);
		}
	}
}