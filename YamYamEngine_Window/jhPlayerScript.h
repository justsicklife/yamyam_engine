#pragma once
#include "..\\YamYamEngine_SOURCE\jhScript.h"

namespace jh {
	class PlayerScript : public Script
	{
	public :
		PlayerScript();
		~PlayerScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
	private :
	};
}