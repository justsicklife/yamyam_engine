#include "jhPlayScene.h"
#include "jhGameObject.h"
#include "jhPlayer.h"
#include "jhTransform.h"
#include "jhSpriteRenderer.h"
#include "jhInput.h"
#include "jhSceneManager.h"
#include "jhObject.h"

namespace jh {

	PlayScene::PlayScene() {

	}

	PlayScene::~PlayScene() {

	}

	void PlayScene::Initialize() {

		{
			//bg = new Player();
			//Transform* tr
			//	= bg->AddComponent<Transform>();
			//tr->SetPosition(Vector2(0, 0));

			//tr->SetName(L"TR");

			//SpriteRenderer* sr
			//	= bg->AddComponent<SpriteRenderer>();
			//sr->SetName(L"SR");
			//sr->ImageLoad(
			//	L"D:/WinProj/YamYamEngine/Resources/CloudOcean.png"
			//);

			//AddGameObject(bg, eLayerType::BackGround);
			bg = object::Instantiate<Player>
				(enums::eLayerType::BackGround,Vector2(100.0f,100.0f));
		
			SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
			sr->ImageLoad(L"D:/WinProj/YamYamEngine/Resources/CloudOcean.png");

		}
	}

	void PlayScene::Update()
	{
		Scene::Update();
	}
	
	void PlayScene::LateUpdate() {
		Scene::LateUpdate();

		if (Input::GetKeyDown(eKeyCode::N)) {
			SceneManager::LoadScene(L"TitleScene");
		}
 	}

	void PlayScene::Render(HDC hdc) {
		Scene::Render(hdc);
	}

	void PlayScene::OnEnter()
	{
		
	}

	void PlayScene::OnExit()
	{
		//Transform* tr
		//	= bg->GetComponent<Transform>();
		//tr->SetPosition(Vector2(0, 0));
	}
		
}