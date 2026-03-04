#include "jhPlayer.h"
#include "jhTransform.h"
#include "jhMath.h"
#include "jhTime.h"

namespace jh
{

	void Player::Initialize()
	{
		this->playerTransform = this->GetComponent<Transform>();
	}

	void Player::Update()
	{

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