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

	void Layer::FlushDeleteObjects()
	{
		for (int i = 0; i < mDeleteGameObjects.size(); i++) {
			for (int j = 0; j < mGameObjects.size() ; j++) {
				if (mDeleteGameObjects[i] == mGameObjects[j]) {
					mGameObjects.erase(mGameObjects.begin() + j);
				}
			}
		}

		mDeleteGameObjects.clear();
	}

	void Layer::AddGameObject(GameObject* gameObject)
	{
		mPendingGameObejects.push_back(gameObject);
	}

	void Layer::DeleteGameObject(GameObject* gameObject)
	{
		mDeleteGameObjects.push_back(gameObject);
	}

}