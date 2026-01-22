#pragma once
#include "..\\YamYamEngine_SOURCE\\jhScene.h"

namespace jh {
	class PlayScene : public Scene {
	public :
		PlayScene();
		~PlayScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
	private :

	};
}