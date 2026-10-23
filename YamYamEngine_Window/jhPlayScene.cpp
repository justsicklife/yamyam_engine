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

			mPlayer->GetComponent<Transform>()->SetScale(Vector2(2.0f, 2.0f));
			mPlayer->GetComponent<Transform>()->SetRotation(30.0f);

			mPlayer->AddComponent<PlayerScript>();

			Transform* playerTr = mPlayer->GetComponent<Transform>();

			playerTr->SetPosition(Vector2(10.0f,10.0f));

			Animator* animator = mPlayer->AddComponent<Animator>();

			graphcis::Texture* catTexture = Resources::Find<graphcis::Texture>(L"Cat");

			animator->CreateAnimation(
				L"DownWalk", catTexture,
				Vector2(0.0f, 0.0f), Vector2(32.0f, 32.0f),
				Vector2::Zero,
				4, 0.5f
			);

			animator->CreateAnimation(
				L"RightWalk", catTexture,
				Vector2(0.0f, 32.0f), Vector2(32.0f, 32.0f),
				Vector2::Zero,
				4, 0.5f
			);

			animator->CreateAnimation(
				L"UpWalk", catTexture,
				Vector2(0.0f, 64.0f), Vector2(32.0f, 32.0f),
				Vector2::Zero,
				4, 0.5f
			);

			animator->CreateAnimation(
				L"LeftWalk", catTexture,
				Vector2(0.0f, 96.0f), Vector2(32.0f, 32.0f),
				Vector2::Zero,
				4, 0.5f
			);

			animator->CreateAnimation(
				L"SitDown", catTexture,
				Vector2(0.0f, 128.0f), Vector2(32.0f, 32.0f),
				Vector2::Zero,
				4, 0.5f
			);

			animator->CreateAnimation(
				L"Grooming	", catTexture,
				Vector2(0.0f, 160.0f), Vector2(32.0f, 32.0f),
				Vector2::Zero,
				4, 0.5f
			);

			animator->PlayAnimation(L"SitDown",false);

			GameObject* bubble = object::Instantiate<GameObject>(enums::eLayerType::Particle, Vector2(0.0f, 0.0f));

			SpriteRenderer* bubbleSr =  bubble->AddComponent<SpriteRenderer>();

			graphcis::Texture* bubbleTexture = Resources::Find<graphcis::Texture>(L"Bubble");

			bubbleSr->SetTexture(bubbleTexture);

			bubble->GetComponent<Transform>()->SetPosition(Vector2(100.0f,100.0f));

			GameObject* effect = object::Instantiate<GameObject>(enums::eLayerType::Effect, Vector2(0.0f, 0.0f));

			graphcis::Texture* effectTexture = Resources::Find<graphcis::Texture>(L"Effect");

			Animator* animEffect = effect->AddComponent<Animator>();

			animEffect->CreateAnimation(
				L"MapleEffect"
				,effectTexture
				,Vector2(0.0f,0.0f)
				,Vector2(386.0f,246.0f)
				,Vector2(0.0f,0.0f)
				,8
				,0.1f
			);

			animEffect->PlayAnimation(L"MapleEffect");

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