#include "jhLayer.h"

namespace jh {
	Layer::Layer() : mGameObjects{}, mPendingGameObejects{} {
	}

	Layer::~Layer()
	{

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

	void Layer::FlushPendingObjects()
	{
		for (GameObject* gameObj : mPendingGameObejects) {
			mGameObjects.push_back(gameObj);
		}

		mPendingGameObejects.clear();
	}

	void Layer::AddGameObject(GameObject* gameObject)
	{
		mPendingGameObejects.push_back(gameObject);
	}
}