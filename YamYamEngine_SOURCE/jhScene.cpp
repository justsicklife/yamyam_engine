#include "jhEntity.h"
#include "jhGameObject.h"
#include "jhScene.h"

namespace jh {
	
	Scene::Scene()
		: mGameObjects{} {

	}
		
	Scene::~Scene() {

	}

	void Scene::Initialize() {

	}

	void Scene::Update() {
		//for (size_t i = 0; i < mGameObjects.size(); i++) {
		//	mGameObjects[i]->Update();
		//}
		// 범위 기반 for 문
		for (GameObject* gameObj : mGameObjects) 
		{
			gameObj->Update();
		}
	}

	void Scene::LateUpdate() {
		
	}

	void Scene::Render(HDC hdc) {
		for (GameObject* gameObj : mGameObjects)
		{
			gameObj->Render(hdc);
		}
	}

	void Scene::AddGameObject(GameObject* gameObject) {
		mGameObjects.push_back(gameObject);
	}
}