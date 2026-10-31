#include "jhPlayScene.h"
#include "jhGameObject.h"
#include "jhPlayer.h"
#include "jhTransform.h"
#include "jhSpriteRenderer.h"
#include "jhInput.h"
#include "jhSceneManager.h"
#include "jhObject.h"
#include "jhTexture.h"
#include "jhResources.h"
#include "jhPlayerScript.h"
#include "jhCamera.h"
#include "jhRenderer.h"
#include "jhAnimator.h"
#include "jhCat.h"
#include "jhCatScript.h"

namespace jh {

	PlayScene::PlayScene() : mPlayer(nullptr) {

	}

	PlayScene::~PlayScene() {

	}

	void PlayScene::Initialize() {
		{
			// main Camera
			GameObject* camera = object::Instantiate<GameObject>(enums::eLayerType::None,Vector2(344.0f,442.0f));
			Camera* cameraComp = camera->AddComponent<Camera>();
			renderer::mainCamera = cameraComp;

			//camera->AddComponent<PlayerScript>();

			// 게임 오브젝트 만들기 전에 리소스들 전부 Load 해두면 좋다.

			mPlayer = object::Instantiate<Player>
				(enums::eLayerType::Player);

			mPlayer->GetComponent<Transform>()->SetScale(Vector2(2.0f, 2.0f));
			mPlayer->GetComponent<Transform>()->SetPosition(Vector2(100.0f,100.0f));

			PlayerScript* plScript = mPlayer->AddComponent<PlayerScript>();

			Transform* playerTr = mPlayer->GetComponent<Transform>();

			graphcis::Texture* playerTexture = Resources::Find<graphcis::Texture>(L"Player");

			playerTr->SetPosition(Vector2(10.0f,10.0f));

			Animator* playerAnimator = mPlayer->AddComponent<Animator>();

			playerAnimator->CreateAnimation(
				L"Idle",
				playerTexture,
				Vector2(2000.0f, 250.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 1, 0.1f
			);

			playerAnimator->CreateAnimation(
				L"FrontGiveWater",
				playerTexture,
				Vector2(0.0f, 2000.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 12, 0.1f
			);

			playerAnimator->GetCompleteEvent(L"FrontGiveWater") = std::bind(&PlayerScript::AttackEffect, plScript);

			playerAnimator->PlayAnimation(L"Idle", false);

			

			/// Cat
			Cat* cat = object::Instantiate<Cat>(enums::eLayerType::Animal);

			cat->AddComponent<CatScript>();
			
			Animator* catAnimator = cat->AddComponent<Animator>();

			graphcis::Texture* catTexture = Resources::Find<graphcis::Texture>(L"Cat");

			catAnimator->CreateAnimation(
				L"DownWalk", catTexture,
				Vector2(0.0f, 0.0f), Vector2(32.0f, 32.0f),
				Vector2::Zero,
				4, 0.5f
			);

			catAnimator->CreateAnimation(
				L"RightWalk", catTexture,
				Vector2(0.0f, 32.0f), Vector2(32.0f, 32.0f),
				Vector2::Zero,
				4, 0.5f
			);

			catAnimator->CreateAnimation(
				L"UpWalk", catTexture,
				Vector2(0.0f, 64.0f), Vector2(32.0f, 32.0f),
				Vector2::Zero,
				4, 0.5f
			);

			catAnimator->CreateAnimation(
				L"LeftWalk", catTexture,
				Vector2(0.0f, 96.0f), Vector2(32.0f, 32.0f),
				Vector2::Zero,
				4, 0.5f
			);

			catAnimator->CreateAnimation(
				L"SitDown", catTexture,
				Vector2(0.0f, 128.0f), Vector2(32.0f, 32.0f),
				Vector2::Zero,
				4, 0.5f
			);

			catAnimator->CreateAnimation(
				L"Grooming", catTexture,
				Vector2(0.0f, 160.0f), Vector2(32.0f, 32.0f),
				Vector2::Zero,
				4, 0.5f
			);

			catAnimator->CreateAnimation(
				L"LayDown", catTexture,
				Vector2(0.0f, 192.0f), Vector2(32.0f, 32.0f),
				Vector2::Zero,
				4, 0.5f
			);

			catAnimator->PlayAnimation(L"SitDown", false);

			cat->GetComponent<Transform>()->SetPosition(Vector2(200.0f,200.0f));

			cat->GetComponent<Transform>()->SetScale(Vector2(2.0f, 2.0f));

			cameraComp->SetTarget(cat);
				
			Scene::Initialize();
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
		//	= mPlayer->GetComponent<Transform>();
		//tr->SetPosition(Vector2(0, 0));
	}
		
}


//25분