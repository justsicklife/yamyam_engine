#include "jhApple.h"
#include "jhInput.h"
#include "jhTransform.h"
#include "jhTime.h"
#include "jhObject.h"
#include "jhSpriteRenderer.h"
#include "jhResources.h"

namespace jh
{

	void Apple::OnEaten(Snake* snake)
	{
		snake->Grow();
	}

	void Apple::Initialize()
	{
		SpriteRenderer* sr = AddComponent<SpriteRenderer>();

		graphcis::Texture* apple = Resources::Find<graphcis::Texture>(L"Apple");

		this->SetPosition(math::Vector2(2.0f,2.0f));

		sr->SetSize(math::Vector2(4.0f, 4.0f));

		sr->SetTexture(apple);
	}

	void Apple::Update()
	{
		GameObject::Update();
	}

	void Apple::LateUpdate()
	{
		math::Vector2 snakePosition =  GetSnake()->GetSnakeHead()->GetPosition();

		if (GetPosition() == snakePosition && !isColliding) {
			isColliding = true;
			OnEaten(GetSnake());
			delete this;
		}

		GameObject::LateUpdate();	
	}

	void Apple::Render(HDC hdc)
	{
		math::Vector2 pos = GetPosition();

		Transform* transform = GetComponent<Transform>();

		transform->SetPosition({ 250.0f + pos.x * 64 ,250.0f + pos.y * 64 });

		GameObject::Render(hdc);
	}


	eItemType Apple::GetItemType()
	{
		return eItemType::Apple;
	}
}