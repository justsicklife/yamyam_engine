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
#include <cstdlib>
#include <ctime>

namespace jh
{

	Item* Apple::OnEaten(Snake* snake)
	{
		object::Destroy(enums::eLayerType::Player, this);
		Apple* apple = object::Instantiate<Apple>(enums::eLayerType::Player, math::Vector2::Zero);
		
		SpriteRenderer* sr = apple->AddComponent<SpriteRenderer>();

		graphcis::Texture* appleTexture = Resources::Find<graphcis::Texture>(L"Apple");
		
		sr->SetSize(math::Vector2(4.0f, 4.0f));

		sr->SetTexture(appleTexture);

		math::Vector2 randomPosition = GetSpawnPosition(snake);
		apple->Spawn(randomPosition);
		return apple;
	}

	void Apple::ApplyEffect(Snake* snake)
	{
		snake->Grow();
	}

	void Apple::Initialize()
	{
		SpriteRenderer* sr = AddComponent<SpriteRenderer>();

		graphcis::Texture* apple = Resources::Find<graphcis::Texture>(L"Apple");

		Spawn(math::Vector2(5.0f,5.0f));

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

	math::Vector2 Apple::GetSpawnPosition(Snake* snake)
	{
		std::vector<math::Vector2> snakeAllPositions = snake->GetBodyPositions();

		TileMap* tileMap = snake->GetTileMap();

		int width = tileMap->GetWidth();
		int height = tileMap->GetHeight();

		//뱀의 위치를 제외한 좌표를 얻고 
		// 거기서 랜덤한 위치에 사과 생성

		std::vector<math::Vector2> emptyPositions;

		for (int x = 0; x < height; x++)
		{
			for (int y = 0; y < width; y++)
			{
				math::Vector2 current(x, y);

				bool isSnake = false;

				for (const math::Vector2& snakePos : snakeAllPositions)
				{
					if (snakePos == current)
					{
						isSnake = true;
						break;
					}
				}

				if (!isSnake)
					emptyPositions.push_back(current);
			}
		}

		int len = emptyPositions.size();

		if (len == 0)
			return math::Vector2(-1.0f,-1.0f);

		int randomIndex = rand() % len;

		return emptyPositions[randomIndex];
	}

	void Apple::Spawn(math::Vector2 position)
	{
		this->SetPosition(position);
	}
}