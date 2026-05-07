#include "jhSnakeHead.h"
#include "jhTransform.h"
#include "jhSpriteRenderer.h"
#include "jhResources.h"

namespace jh {

	void SnakeHead::Initialize()
	{
		SpriteRenderer* sr = AddComponent<SpriteRenderer>();

		sr->SetSize(math::Vector2(4.0f, 4.0f));

		graphcis::Texture* headTexture = Resources::Find<graphcis::Texture>(L"Head");
		sr->SetTexture(headTexture);

		SetPos(math::Vector2(0.0f, 0.0f));
	}
	
	void SnakeHead::Update()
	{

	}
	
	void SnakeHead::LateUpdate()
	{

	}
	
	void SnakeHead::Render(HDC hdc)
	{
		Transform* transform = GetComponent<Transform>();

		math::Vector2 pos = GetPos();

		transform->SetPosition({250.0f+pos.x * 64,250.0f+pos.y * 64});

		GameObject::Render(hdc);
	}

}