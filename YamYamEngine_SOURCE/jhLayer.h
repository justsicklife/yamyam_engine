#pragma once
#include "jhEntity.h"
#include "CommonInclude.h"
#include "jhGameObject.h"

namespace jh {
	/// <summary>
	/// 레이어 인데 배열로 게임오브젝트를 가지고있음
	/// </summary>
	class Layer : public Entity
	{
	public:
		Layer();
		~Layer();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		void AddGameObject(GameObject* gameObject);

	private:
		//eLayerType mType;
		std::vector<GameObject*> mGameObjects;
	};
}