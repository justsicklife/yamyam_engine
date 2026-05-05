#pragma once
#include "..\\YamYamEngine_SOURCE\\\jhGameObject.h"
#include "..\\YamYamEngine_SOURCE\\\jhMath.h"

namespace jh {

	enum class Direction {
		Up,
		Right,
		Down,
		Left,
		None
	};

	class Snake : public GameObject
	{
	public:
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetPos(int x,int y) {
			pos.x = x;
			pos.y = y;
		}

		math::Vector2 GetPos() {
			return pos;
		}

		void Move();

	private:
		math::Vector2 pos;
		Direction dir;
		float currentTIme;
	};
}