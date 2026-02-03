#include "..\\YamYamEngine_SOURCE\jhScene.h"
#pragma once

namespace jh {
	class EndScene : public Scene {
	public:
		EndScene();
		~EndScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
	private :
	};
}