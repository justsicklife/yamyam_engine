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

namespace jh {

	PlayScene::PlayScene() {

	}

	PlayScene::~PlayScene() {

	}

	void PlayScene::Initialize() {
		{
			// main Camera
			GameObject* camera = object::Instantiate<GameObject>(enums::eLayerType::None);
			camera->AddComponent<Camera>();
			camera->AddComponent<PlayerScript>();

			// 게임 오브젝트 만들기 전에 리소스들 전부 Load 해두면 좋다.

			bg = object::Instantiate<Player>
				(enums::eLayerType::BackGround,Vector2(100.0f,100.0f));
		
			SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
			
			//bg->AddComponent<PlayerScript>();

			graphcis::Texture* bgTex = Resources::Find<graphcis::Texture>(L"BG");

			sr->SetTexture(bgTex);
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