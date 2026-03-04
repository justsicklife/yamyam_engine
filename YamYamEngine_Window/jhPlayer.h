#pragma once
#include "..\\YamYamEngine_SOURCE\\\jhGameObject.h"
#include "jhTransform.h"

namespace jh {
	class Player : public GameObject
	{
	public :
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private :
		Transform* playerTransform;
	};
}