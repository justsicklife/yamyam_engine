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
		/// LateUpdate 에서 보류중인 삭제될 게임오브젝트를
		/// 실제 게임오브젝트에서 실제로 플러시(보류중인 게임오브젝트) 하여 
		/// 삭제하는 것
		/// </summary>
		void FlushDeleteObjects();

		/// <summary>
		/// LateUpdate 에서 게임오브젝트 추가가 보류 중인 
		/// 게임오브젝트들을 실제 mGameObjects 에 플러시 하는 메서드
		/// </summary>
		void FlushPendingObjects();

		void AddGameObject(GameObject* gameObject);

		void DeleteGameObject(GameObject* gameObject);

	private:
		//eLayerType mType;
		std::vector<GameObject*> mGameObjects;
		std::vector<GameObject*> mPendingGameObejects;
		std::vector<GameObject*> mDeleteGameObjects;
	};
}