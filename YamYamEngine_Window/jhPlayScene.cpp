#include "jhPlayScene.h"
#include "jhGameObject.h"
#include "jhPlayer.h"
#include "jhTransform.h"
#include "jhSpriteRenderer.h"
#include "jhResources.h"
#include "jhEnums.h"

namespace jh {

	PlayScene::PlayScene() {

	}

	PlayScene::~PlayScene() {

	}

	void PlayScene::Initialize() {

		{
			Player* bg = new Player();
			Transform* tr
				= bg->AddComponent<Transform>();
			tr->SetPos(Vector2(0, 0));

			tr->SetName(L"TR");

			//SpriteRenderer* sr
			//	= bg->AddComponent<SpriteRenderer>();
			//sr->SetName(L"SR");
			//sr->ImageLoad(
			//	L"D:/WinProj/YamYamEngine/Resources/you.png"
			//);

			SpriteRenderer* sr
				= bg->AddComponent<SpriteRenderer>();

			sr->SetName(L"AA");

			wstring fullPath = Resources::path;
			// 2. Map에서 데이터를 찾아 합치기
			auto it = Resources::ObjectImagePath.find(ObjectType::Baba);

			if (it != Resources::ObjectImagePath.end()) {
				// std::wstring은 + 연산자로 문자열을 합칠 수 있습니다.
				fullPath += it->second;
			}

			sr->ImageLoad(fullPath);

			AddGameObject(bg);
		}
	}

	void PlayScene::Update()
	{
		Scene::Update();
	}
	
	void PlayScene::LateUpdate() {
		Scene::LateUpdate();
	}

	void PlayScene::Render(HDC hdc) {
		Scene::Render(hdc);
	}

}