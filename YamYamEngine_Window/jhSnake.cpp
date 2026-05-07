#include "jhSnake.h"
#include "jhSpriteRenderer.h"
#include "jhResources.h"
#include "jhTransform.h"
#include "jhInput.h"
#include "jhTime.h"
#include "jhObject.h"

namespace jh {

	void Snake::Initialize()
	{
		head = object::Instantiate<SnakeHead>(enums::eLayerType::Player, math::Vector2(250.0f,250.0f));
		head->Initialize();

		graphcis::Texture* headTexture = Resources::Find<graphcis::Texture>(L"Head");


		{
			SnakeBody* body1 = object::Instantiate<SnakeBody>(enums::eLayerType::Player, math::Vector2(250.0f, 250.0f));
			
			body1->Initialize();

			body1->SetPos({ 0.0f,1.0f });

			bodies.PushBack(body1);
		}

		{
			SnakeBody* body2 = object::Instantiate<SnakeBody>(enums::eLayerType::Player, math::Vector2(250.0f, 250.0f));

			body2->Initialize();


			body2->SetPos({ 0.0f,2.0f });


			bodies.PushBack(body2);
		}

		currentTIme = 0.0f;
		dir = Direction::None;

	}

	void Snake::Update()
	{
		if (Input::GetKeyDown(eKeyCode::W)) {
			dir = Direction::Up;
		}
		else if (Input::GetKeyDown(eKeyCode::D)) {
			dir = Direction::Right;
		}
		else if (Input::GetKeyDown(eKeyCode::S)) {
			dir = Direction::Down;
		}
		else if (Input::GetKeyDown(eKeyCode::A)) {
			dir = Direction::Left;
		}

		if (currentTIme >= 0.5f) {
			if (dir != Direction::None) {

				math::Vector2 stepPos;

				if (Step(stepPos)) {
					UpdateBodyPositions(stepPos);
				}
			}

			currentTIme = 0.0f;
		}

		currentTIme += Time::DeltaTime();
	}

	void Snake::LateUpdate()
	{

	}

	void Snake::Render(HDC hdc)
	{	
		head->Render(hdc);

		Node<SnakeBody*>* curBody = bodies.GetHead();

		while (curBody != nullptr) {
			curBody->data->Render(hdc);
			curBody = curBody->next;
		}
	}

	// Step : 뱀이 이동한 자리가 조건에 맞는지 검사하고 
	// 인자의 참조자로 메서드 외부에 있는 prevPos 를 대입해줌 
	// 인자 : prevPos : 뱀의 머리가 움직인 자리
	// 반환형 : bool : 벽 바깥에 나가면 false 
	// 벽 안에서 움직이면 true
	bool Snake::Step(math::Vector2& prevPos)
 	{
		prevPos = head->GetPos();
		math::Vector2 currPos = prevPos;

		if (dir == Direction::Up) {
			currPos.y -= 1;
		}
		else if (dir == Direction::Right) {
			currPos.x += 1;
		}
		else if (dir == Direction::Down) {
			currPos.y += 1;
		}
		else if (dir == Direction::Left) {
			currPos.x -= 1;
		}

		if (IsOutOfBounds(currPos)) {
			head->SetPos(currPos);
			return true;
		}

		return false;
	}

	void Snake::UpdateBodyPositions(math::Vector2 stepPos)
	{

		Node<SnakeBody*>* curBody = bodies.GetHead();

		math::Vector2 prevPos;


		while (curBody != nullptr) {
			// 문제 
			// 1. 현재 바디에 있는 값을 추출한다.
			math::Vector2 prevPos = curBody->data->GetPos();
			// 2. 추출한후 전에 값으로 변경한다
			curBody->data->SetPos(stepPos);
			stepPos = prevPos;
			// 3. 그다음 노드로 이동한다.
			curBody = curBody->next;
		}
	}

	bool Snake::IsOutOfBounds(math::Vector2 nextPos)
	{
		if (0 <= nextPos.x && 7 > nextPos.x && 0 <= nextPos.y && 7 > nextPos.y) {
			return true;
		}

		return false;
	}

}