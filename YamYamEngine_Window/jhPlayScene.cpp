#include "jhPlayScene.h"
#include "jhGameObject.h"
#include "jhApple.h"
#include "jhTransform.h"
#include "jhSpriteRenderer.h"
#include "jhInput.h"
#include "jhSceneManager.h"
#include "jhObject.h"
#include "jhTexture.h"
#include "jhResources.h"
#include "jhTile.h"
#include <vector>

namespace jh {

	PlayScene::PlayScene() {

	}

	PlayScene::~PlayScene() {

	}

	void PlayScene::Initialize() {
		{
			// 게임 오브젝트 만들기 전에 리소스들 전부 Load 해두면 좋다.

			apple = object::Instantiate<Apple>
				(enums::eLayerType::Player,Vector2(0.0f,0.0f));
		
			apple->Initialize();

			background = object::Instantiate<BackGround>(enums::eLayerType::BackGround, Vector2(250.0f, 250.0f));

			background->Initialize();

			snake = new Snake();

			snake->Initialize();
		}
	}

	void PlayScene::Update()
	{
		snake->Update();
	}
	
	void PlayScene::LateUpdate() {
		Scene::LateUpdate();

		if (Input::GetKeyDown(eKeyCode::N)) {
			SceneManager::LoadScene(L"TitleScene");
		}
 	}

	void PlayScene::Render(HDC hdc) {
		apple->Render(hdc);

		background->Render(hdc);
		
		snake->Render(hdc);
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