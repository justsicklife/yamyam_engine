#include "jhSnakeBody.h"
#include "jhSpriteRenderer.h"
#include "jhResources.h"
#include "jhTransform.h"

namespace jh {

	void SnakeBody::Initialize()
	{
		graphcis::Texture* headTexture = Resources::Find<graphcis::Texture>(L"Body");

		SpriteRenderer* sr = AddComponent<SpriteRenderer>();

		sr->SetSize(math::Vector2(4.0f, 4.0f));

		sr->SetTexture(headTexture);
	}
	void SnakeBody::Update()
	{
	}
	void SnakeBody::LateUpdate()
	{
	}
	void SnakeBody::Render(HDC hdc)
	{
		Transform* transform = GetComponent<Transform>();

		math::Vector2 pos = GetPosition();

		transform->SetPosition({ 250.0f + pos.x * 64,250.0f + pos.y * 64 });

		// GameObject::Render 를 마지막에 해주는 이유
		// GameObject 안에 있는 Component 들을 모두 Render 해줌
		GameObject::Render(hdc);

	}
}