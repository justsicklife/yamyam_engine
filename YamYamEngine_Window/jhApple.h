#pragma once
#include "..\\YamYamEngine_SOURCE\\\jhGameObject.h"

namespace jh {
	class Apple : public GameObject
	{
	public :
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private :

	};
}