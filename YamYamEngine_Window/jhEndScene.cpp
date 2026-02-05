#include "jhGameObject.h"
#include "jhEndScene.h"
#include "jhPlayer.h"
#include "jhTransform.h"
#include "jhSpriteRenderer.h"


namespace jh {

	EndScene::EndScene() {

	}

	EndScene::~EndScene() {

	}

	void EndScene::Initialize() {

	}

	void EndScene::Update() {
		Scene::Update();
	}

	void EndScene::LateUpdate() {
		Scene::LateUpdate();
	}

	void EndScene::Render(HDC hdc) {
		Scene::Render(hdc);
	}
}