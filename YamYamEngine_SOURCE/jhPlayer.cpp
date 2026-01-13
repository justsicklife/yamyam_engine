#include "jhPlayer.h"
#include "jhInput.h"
#include "jhTime.h"
#include <algorithm>

namespace jh {
	

	Player::Player() : 
		moveT(0.0f),
		target({0,0}),
		start({0,0}),
		elapsedTime(0.0f),
		moveDuration(1.0f),
		isMove(false)
	{

	}

	Vector2 Player::MoveTarget(Vector2 start, Vector2 target, float t) {
		float nextX = (1 - t) * start.x + t * target.x;
		float nextY = (1 - t) * start.y + t * target.y;

		Vector2 next = {nextX,nextY };

		return next;
	}

    void Player::Update() {

        // 이동 중이 아닐 때만 입력 처리
        if (!isMove) {
            Vector2 currentPos = { GetPositionX(), GetPositionY() };

            if (Input::GetKey(eKeyCode::A)) {
                start = currentPos;
                target = { start.x - tileSize, start.y };
                elapsedTime = 0.0f;
                isMove = true;
            }
            else if (Input::GetKey(eKeyCode::D)) {
                start = currentPos;
                target = { start.x + tileSize, start.y };
                elapsedTime = 0.0f;
                isMove = true;
            }
            else if (Input::GetKey(eKeyCode::W)) {
                start = currentPos;
                target = { start.x, start.y - tileSize };
                elapsedTime = 0.0f;
                isMove = true;
            }
            else if (Input::GetKey(eKeyCode::S)) {
                start = currentPos;
                target = { start.x, start.y + tileSize };
                elapsedTime = 0.0f;
                isMove = true;
            }
        }

        // 이동 중일 때만 보간
        if (isMove) {
            elapsedTime += Time::DeltaTime();
            float t = elapsedTime / moveDuration;

            if (t >= 1.0f) {
                t = 1.0f;
                isMove = false;
            }

            Vector2 pos = MoveTarget(start, target, t);
            SetPosition(pos.x, pos.y);
        }
    }

}