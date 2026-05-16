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
		
		/// <summary>
		/// LateUpdate 에서 게임오브젝트 추가가 보류 중인 
		/// 게임오브젝트들을 실제 mGameObjects 에 플러시 하는 메서드
		/// </summary>
		void FlushPendingObjects();

		void AddGameObject(GameObject* gameObject);

	private:
		//eLayerType mType;
		std::vector<GameObject*> mGameObjects;
		std::vector<GameObject*> mPendingGameObejects;
	};
}