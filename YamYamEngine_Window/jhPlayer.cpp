#include "jhPlayer.h"
#include "jhTransform.h"
#include "jhMath.h"
#include "jhTime.h"

namespace jh
{
	float duration = 1.0f;
	float elapsed = 0.0f;

	void Player::Initialize()
	{
		GameObject::Initialize();
	}

	void Player::Update()
	{
		Transform* playerTranform  = this->GetComponent<Transform>();
		Vector2 pos = playerTranform->GetPosition();
		//Vector2 nPos = Vector2(100, 0);

		//elapsed += Time::DeltaTime();

		//float t = elapsed / duration;
		//if (t > 1.0f) t = 1.0f;

		//Vector2 curPos = Vector2::Lerp(pos, nPos, t);
		// 
		//playerTranform->SetPos(curPos);
	}

	void Player::LateUpdate()
	{
		GameObject::LateUpdate();
	}

	void Player::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}