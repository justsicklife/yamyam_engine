#pragma once
#include "..\\YamYamEngine_SOURCE\\\jhGameObject.h"
#include "..\\YamYamEngine_SOURCE\\\jhMath.h"

namespace jh {

	class SnakeHead : public GameObject
	{
	public :
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetPos(math::Vector2 pos) {
			position = pos;
		}

		math::Vector2 GetPos() {
			return position;
		}

	private:
		math::Vector2 position;
	};

}
