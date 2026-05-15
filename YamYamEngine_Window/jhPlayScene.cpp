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

			snake->SetTileMap(tileMap);

			snake->Initialize();
		}
	}

	void PlayScene::Update()
	{
		snake->Update();
	}
	
	void PlayScene::LateUpdate() {
		Scene::LateUpdate();

		itemManager->LateUpdate();

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
		
}