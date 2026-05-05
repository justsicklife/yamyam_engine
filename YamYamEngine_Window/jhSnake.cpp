#include "jhSnake.h"
#include "jhSpriteRenderer.h"
#include "jhResources.h"
#include "jhTransform.h"
#include "jhInput.h"
#include "jhTime.h"

namespace jh {

	void Snake::Initialize()
	{

		math::Vector2 pos = GetPos();

		Transform* transform = GetComponent<Transform>();

		transform->SetPosition(math::Vector2(250.0f + pos.x * 64, 250.0f + pos.y * 64));

		SpriteRenderer* sr = AddComponent<SpriteRenderer>();

		graphcis::Texture* head = Resources::Find<graphcis::Texture>(L"Head");

		sr->SetSize(math::Vector2(4.0f, 4.0f));

		sr->SetTexture(head);
		
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
			Move();
			currentTIme = 0.0f;
		}

		currentTIme += Time::DeltaTime();
	}

	void Snake::LateUpdate()
	{


	}

	void Snake::Render(HDC hdc)
	{

		GameObject::Render(hdc);

	}

	void Snake::Move()
	{
		math::Vector2 pos = GetPos();

		if (dir == Direction::Up) {
			pos.y -= 1;
		}
		else if (dir == Direction::Right)
		{
			pos.x += 1;
		}
		else if (dir == Direction::Down) {
			pos.y += 1;
		}
		else if (dir == Direction::Left) {
			pos.x -= 1;
		}
		else {
			return;
		}

		SetPos(pos.x ,pos.y );

		Transform* transform = GetComponent<Transform>();

		transform->SetPosition(math::Vector2(250.0f + pos.x * 64, 250.0f + pos.y * 64));
	}
}