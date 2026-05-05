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

			Snake* head =  object::Instantiate<Snake>(enums::eLayerType::Player, Vector2(0.0f, 0.0f));


			Snake* tail = object::Instantiate<Snake>(enums::eLayerType::Player, Vector2(0.0f, 0.0f));

			head->SetPos(4, 0);

			tail->SetPos(5, 0);

			head->Initialize();

			tail->Initialize();


			snakeList.PushFront(head);

			snakeList.PushFront(tail);

		}
	}

	void PlayScene::Update()
	{
		Node<Snake*>* currentSnake = snakeList.GetHead();

		while (currentSnake != nullptr) {
			currentSnake->data->Update();
			currentSnake = currentSnake->next;
		}
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

		Node<Snake*>* currentSnake = snakeList.GetHead();

		while (currentSnake != nullptr) {
			currentSnake->data->Render(hdc);
			currentSnake = currentSnake->next;
		}
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