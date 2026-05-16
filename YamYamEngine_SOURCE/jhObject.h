#pragma once
#include "jhComponent.h"
#include "jhGameObject.h"
#include "jhLayer.h"
#include "jhScene.h"
#include "jhSceneManager.h"
#include "jhTransform.h"

namespace jh::object 
{
	/*template <typename T>
	static T* Instantiate(jh::enums::eLayerType type) {
		T* gameObject = new T();
		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObject);

		return gameObject;
	}

	template <typename T>
	static T* Instantiate(jh::enums::eLayerType type,math::Vector2 position) {
		T* gameObject = new T();
		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObject);
		
		Transform* tr = gameObject->GetComponent<Transform>();
		tr->SetPosition(position);

		return gameObject;
	}*/

	template <typename T>
	static T* Instantiate(jh::enums::eLayerType type) {
		T* gameObject = new T();
		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObject);

		return gameObject;
	}

	template <typename T>
	static T* Instantiate(jh::enums::eLayerType type, math::Vector2 position) {
		T* gameObject = new T();
		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObject);

		Transform* tr = gameObject->GetComponent<Transform>();
		tr->SetPosition(position);

		return gameObject;
	}
}