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

namespace jh {

	PlayScene::PlayScene() {

	}

	PlayScene::~PlayScene() {

	}

	/// <summary>
	/// 오브젝트들을 초기설정 해준다
	/// </summary>
	void PlayScene::Initialize() {
		{
			// 게임 오브젝트 만들기 전에 리소스들 전부 Load 해두면 좋다.

			itemManager = new ItemManager();

			Apple* apple = object::Instantiate<Apple>(enums::eLayerType::Player, Vector2(250.0f, 250.0f));
			apple->Initialize();

			itemManager->AddItem(apple);

			background = object::Instantiate<BackGround>(enums::eLayerType::BackGround, Vector2(250.0f, 250.0f));

			TileMap* tileMap = background->AddComponent<TileMap>();


			tileMap->SetOffset(math::Vector2(250.0f,250.0f));
			tileMap->SetTileeSize(64);

			tileMap->SetHeight(7);
			tileMap->SetWidth(7);

			background->Initialize();

			snake = new Snake();

			//apple->SetSnake(snake);

			snake->SetTileMap(tileMap);

			snake->Initialize();
		}
	}

	void PlayScene::Update()
	{
		Scene::Update();

		snake->Update();
	}
	
	void PlayScene::LateUpdate() {
		Scene::LateUpdate();

		snake->LateUpdate();

		// 뱀 머리에 해당하는 좌표를 받아옴
		math::Vector2 snakeHeadPos = snake->GetSnakeHead()->GetPosition();
		// 뱀 머리 좌표에 있는 아이템에 포인터를 가져옴
		Item* item = itemManager->FindItemAt(snakeHeadPos);

		// 문제 한번 충돌하면 프레임 수 만큼 충돌함수가 실행됨
		if (item && snake->isMoving) {
			Collision(snake, item);
		}

		if (Input::GetKeyDown(eKeyCode::N)) {
			SceneManager::LoadScene(L"TitleScene");
		}
 	}

	/// <summary>
	/// 초기 설정한 게임오브젝트들을 렌더해준다.
	/// </summary>
	/// <param name="hdc"></param>
	void PlayScene::Render(HDC hdc) {
		//itemManager->Render(hdc);
		//background->Render(hdc);
		//snake->Render(hdc);

		// Scene에있는 Render 해줘야 되는 이유?
		// Layer 한칸 한칸 마다 게임오브젝트 들을 Render 함
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

	void PlayScene::Collision(Snake* snake, Item* item)
	{
		// 아이템 자신의 변화
		Item* newItem = item->OnEaten(snake);
		// 뱀 자신의 변화
		// 뱀 길이 증가
		snake->OnEat(item);

		itemManager->AddItem(newItem);
		itemManager->DeleteItem(item);
	}
		
}