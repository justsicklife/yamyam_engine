#pragma once
#include "..\\YamYamEngine_SOURCE\\jhScene.h"
#include <vector>
#include <deque>
#include "..\\YamYamEngine_SOURCE\\jhMath.h"
#include "jhBackGround.h"

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
		 class Apple* apple;
		 std::deque<math::Vector2*> mBody;
		 BackGround* background;
	};
}