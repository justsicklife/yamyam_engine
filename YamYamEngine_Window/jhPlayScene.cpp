#include "jhPlayScene.h"
#include "jhGameObject.h"
#include "jhPlayer.h"
#include "jhTransform.h"
#include "jhSpriteRenderer.h"
#include "jhMap.h"

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

			SpriteRenderer* sr
				= bg->AddComponent<SpriteRenderer>();
			sr->SetName(L"SR");
			sr->ImageLoad(
				L"D:/WinProj/YamYamEngine/Resources/you.png"
			);

			AddGameObject(bg);
		}

		{
			Map* map = new Map();

			vector<vector<ObjectType>>& mapArray = map->GetMapArray();
			
			// 어떻게 해야할까?

			for (int y = 0; y < map->height; y++) {
				for (int x = 0; x < map->width; x++) {
					ObjectType type = mapArray[y][x];

					auto iter = map->ObjectImagePath.find(type);
					if (iter == map->ObjectImagePath.end())
						continue;

					const wchar_t* imageName = iter->second;

					const wchar_t* path = map->GetPath();
					
					std::wstring realPath = std::wstring(path) + imageName;

					Player * player = new Player();
					
					Transform* tr = player->AddComponent<Transform>();

					Vector2 pos = Vector2(y * map->TileSize, x * map->TileSize);

					tr->SetPos(pos);

					SpriteRenderer* sr
						= player->AddComponent<SpriteRenderer>();

					sr->SetName(L"baba");
					sr->ImageLoad(realPath);

					AddGameObject(player);

				}
			}
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