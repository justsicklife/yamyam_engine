#include "jhLayer.h"

namespace jh {
	Layer::Layer() : mGameObjects{} {
	}

	Layer::~Layer()
	{
		for (GameObject* gameObj : mGameObjects) {
			if (gameObj == nullptr)
				continue;

			delete gameObj;
			gameObj = nullptr;
		}
	}

	void Layer::Initialize() {
		for (GameObject* gameObj : mGameObjects) {
			gameObj->Initialize();
		}
	}

	void Layer::Update() {
		for (GameObject* gameObj : mGameObjects) {
			gameObj->Update();
		}
	}

	void Layer::LateUpdate() {
		for (GameObject* gameObj : mGameObjects) {
			gameObj->LateUpdate();
		}
	}

	void Layer::Render(HDC hdc) {
		for (GameObject* gameObj : mGameObjects) {
			gameObj->Render(hdc);
		}
	}

	void Layer::AddGameObject(GameObject* gameObject)
	{
		mGameObjects.push_back(gameObject);
	}
}