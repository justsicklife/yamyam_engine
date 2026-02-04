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

		{
			Player* p1 = new Player();
			Transform* tr
				= p1->AddComponent<Transform>();
			tr->SetPos(800, 450);
		
			tr->SetName(L"SR");

			SpriteRenderer* sr
				= p1->AddComponent<SpriteRenderer>();

			AddGameObject(p1);
		}

		{
			Player* p1 = new Player();
			Transform* tr
				= p1->AddComponent<Transform>();
			tr->SetPos(300, 450);

			tr->SetName(L"SR");

			SpriteRenderer* sr
				= p1->AddComponent<SpriteRenderer>();

			AddGameObject(p1);
		}

		{
			Player* p1 = new Player();
			Transform* tr
				= p1->AddComponent<Transform>();
			tr->SetPos(100, 650);

			tr->SetName(L"SR");

			SpriteRenderer* sr
				= p1->AddComponent<SpriteRenderer>();

			AddGameObject(p1);
		}
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