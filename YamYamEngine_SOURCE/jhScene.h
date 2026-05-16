#pragma once
#include "CommonInclude.h"
#include "jhEntity.h"
#include "jhGameObject.h"
#include "jhLayer.h"

namespace jh {
	class Scene : public Entity{
	public:
		Scene();
		~Scene();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);
		virtual void FlushPendingObjects();

		// Scene 이 시작 할때 실행되는 메서드 
		// 예 : 몬스터 위치 초기화
		virtual void OnEnter();
		// Scene 에서 나갈때 실행되는 메서드
		// 예 : 사용하지 않는 몬스터 삭제
		virtual void OnExit();

		void AddGameObject(GameObject* gameObj,enums::eLayerType type);

		Layer* GetLayer(enums::eLayerType type) {
			return mLayers[(UINT)type];
		}

	private :
		std::vector<Layer*> mLayers;
	};
}