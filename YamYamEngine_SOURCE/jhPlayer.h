#pragma once
#include "jhGameObject.h"

namespace jh {
	struct Vector2 {
		float x;
		float y;
	};

	class Player : public GameObject{
	public:

		Player();

		void Update() override;
		// start: 현재 x,y좌표
		// target : 목적지 x,y 좌표
		Vector2 MoveTarget(Vector2 start, Vector2 target, float t);

		float moveT;

		Vector2 start;

		Vector2 target;

		float elapsedTime = 0.0f;
		float moveDuration = 0.0f;

		bool isMove;

		const float tileSize = 50.0f;
	};
}