#include "jhApple.h"
#include "jhInput.h"
#include "jhTransform.h"
#include "jhTime.h"
#include "jhObject.h"
#include "jhSpriteRenderer.h"
#include "jhResources.h"
#include "jhObject.h"
#include <random>
#include "jhSnake.h"

namespace jh
{

	void Apple::OnEaten(Snake* snake)
	{
		object::Destroy(enums::eLayerType::Player, this);
	}

	void Apple::ApplyEffect(Snake* snake)
	{
		snake->Grow();
	}


	void Apple::Initialize()
	{
		SpriteRenderer* sr = AddComponent<SpriteRenderer>();

		graphcis::Texture* apple = Resources::Find<graphcis::Texture>(L"Apple");

		this->SetPosition(math::Vector2(5.0f,5.0f));

		sr->SetSize(math::Vector2(4.0f, 4.0f));

		sr->SetTexture(apple);
	}

	void Apple::Update()
	{
		GameObject::Update();
	}

	void Apple::LateUpdate()
	{
		/*math::Vector2 snakePosition =  GetSnake()->GetSnakeHead()->GetPosition();

		if (GetPosition() == snakePosition && !isColliding) {
			isColliding = true;
			OnEaten(GetSnake());
			object::Instantiate<Apple>(enums::eLayerType::Player, math::Vector2::Zero);
			object::Destroy(enums::eLayerType::Player, this);
		}*/

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