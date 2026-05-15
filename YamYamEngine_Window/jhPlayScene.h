#pragma once
#include "..\\YamYamEngine_SOURCE\\jhScene.h"
#include "..\\YamYamEngine_SOURCE\\jhMath.h"
#include "jhBackGround.h"
#include "..\\YamYamEngine_SOURCE\\jhLinkedList.h"
#include "jhSnake.h"
#include "jhApple.h"
#include "jhItemManager.h"

namespace jh {
	class PlayScene : public Scene {
	public :
		PlayScene();
		~PlayScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void OnEnter() override;
		void OnExit() override;
	private :
		ItemManager* itemManager;
		Snake* snake;
		BackGround* background;
	};
}