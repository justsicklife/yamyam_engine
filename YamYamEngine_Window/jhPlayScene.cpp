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

namespace jh {

	PlayScene::PlayScene() {

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
		
			mPlayer->AddComponent<PlayerScript>();

			Transform* playerTr = mPlayer->GetComponent<Transform>();

			playerTr->SetPosition(Vector2(10.0f,10.0f));

			Animator* animator = mPlayer->AddComponent<Animator>();

			graphcis::Texture* chickenTexture = Resources::Find<graphcis::Texture>(L"Chicken");

			animator->CreateAnimation(
				L"ChickenLeftMove", chickenTexture,
				Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f),
				Vector2::Zero,
				4, 0.5f
			);

			animator->PlayAnimation(L"ChickenLeftMove",true);

			//SpriteRenderer* sr = mPlayer->AddComponent<SpriteRenderer>();
			//
			//sr->SetSize(Vector2(3.0f, 3.0f));

			//graphcis::Texture* pacmanTextrue = Resources::Find<graphcis::Texture>(L"PacMan");

			//sr->SetTexture(pacmanTextrue);

			//graphcis::Texture* packmanTexture = Resources::Find<graphcis::Texture>(L"PacMan");

			//sr->SetTexture(packmanTexture);
		
			/*GameObject* bg = object::Instantiate<Player>
				(enums::eLayerType::BackGround);

			SpriteRenderer* bgSr = bg->AddComponent<SpriteRenderer>();

			bgSr->SetSize(Vector2(3.0f, 3.0f));

			graphcis::Texture* bgTexture = Resources::Find<graphcis::Texture>(L"Chicken");

			bgSr->SetTexture(bgTexture);

			GameObject* chicken = object::Instantiate<Player>(enums::eLayerType::BackGround);*/
		
			// chicken
			//SpriteRenderer* chickenSr = chicken->AddComponent<SpriteRenderer>();

			//graphcis::Texture* chickenTexture = Resources::Find<graphcis::Texture>(L"Chicken");

			//chickenSr->SetTexture(chickenTexture);


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