#pragma once
#include "..\\YamYamEngine_SOURCE\\jhScene.h"

namespace jh {	
	class TitleScene : public Scene
	{
	public:
		TitleScene();
		~TitleScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
	private :

	};
}