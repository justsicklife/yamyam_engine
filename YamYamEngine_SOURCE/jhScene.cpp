#include "jhEntity.h"
#include "jhGameObject.h"
#include "jhScene.h"

namespace jh {
	
	Scene::Scene()
		: mLayers{} {
		mLayers.resize((UINT)eLayerType::Max);
		
		for (size_t i = 0; i < (UINT)eLayerType::Max; i++) {
			mLayers[i] = new Layer();
		}

		int a = 0;
	}
		
	Scene::~Scene() {

	}

	void Scene::Initialize() {
		for (Layer* layer : mLayers)
		{
			if (layer == nullptr) {
				continue;
			}

			layer->Initialize();
		}
	}

	void Scene::Update() {
		//for (size_t i = 0; i < mGameObjects.size(); i++) {
		//	mGameObjects[i]->Update();
		//}
		// 범위 기반 for 문
		for (Layer* layer : mLayers)
		{
			if (layer == nullptr) {
				continue;
			}

			layer->Update();
		}
	}

	void Scene::LateUpdate() {
		for (Layer* layer : mLayers)
		{
			if (layer == nullptr) {
				continue;
			}

			layer->LateUpdate();
		}
	}

	void Scene::Render(HDC hdc) {
		for (Layer* layer : mLayers)
		{
			if (layer == nullptr) {
				continue;
			}

			layer->Render(hdc);
		}
	}

	void Scene::AddGameObject(GameObject* gameObj, eLayerType type)
	{
		mLayers[(UINT)type]->AddGameObject(gameObj);
	}

	void Scene::OnExit()
	{

	}

	void Scene::OnEnter()
	{

	}
}