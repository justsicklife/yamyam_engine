#include "jhApple.h"
#include "jhInput.h"
#include "jhTransform.h"
#include "jhTime.h"
#include "jhObject.h"
#include "jhSpriteRenderer.h"
#include "jhResources.h"

namespace jh
{
	void Apple::Initialize()
	{
		SpriteRenderer* sr = this->AddComponent<SpriteRenderer>();

		graphcis::Texture* apple = Resources::Find<graphcis::Texture>(L"Apple");

		sr->SetSize(math::Vector2(2.5f, 2.5f));

		sr->SetTexture(apple);
	}

	void Apple::Update()
	{
		GameObject::Update();
	}

	void Apple::LateUpdate()
	{
		GameObject::LateUpdate();
		
		if (Input::GetKey(eKeyCode::Right)) {
			Transform* tr = GetComponent<Transform>();
			Vector2 pos = tr->GetPosition();

			pos.x += 100.0f * Time::DeltaTime();
			tr->SetPosition(pos);
		}
	}

	void Apple::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}