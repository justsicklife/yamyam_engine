#include "jhPlayerScript.h"
#include "jhInput.h"
#include "jhTransform.h"
#include "jhTime.h"
#include "jhGameObject.h"
#include "jhAnimator.h"

namespace jh {
	PlayerScript::PlayerScript()
		: mState(jh::PlayerScript::eState::Idle)
		, mAnimator(nullptr)
	{
	}
	PlayerScript::~PlayerScript()
	{
	}
	void PlayerScript::Initialize()
	{
	}
	void PlayerScript::Update()
	{
		if (mAnimator == nullptr) {
			mAnimator = GetOwner()->GetComponent<Animator>();
		}

		switch (mState)
		{
		case jh::PlayerScript::eState::Idle:
			idle();
			break;
		case jh::PlayerScript::eState::Walk:
			move();
			break;
		case jh::PlayerScript::eState::Sleep:
			break;
		case jh::PlayerScript::eState::GiveWater:
			giveWater();
			break;
		case jh::PlayerScript::eState::Attack:
			break;
		default:
			break;
		}
	}
	void PlayerScript::LateUpdate()
	{
	}
	void PlayerScript::Render(HDC hdc)
	{
	}
	void PlayerScript::idle()
	{

		if (Input::GetKey(eKeyCode::LButton)) 
		{
			mState = PlayerScript::eState::GiveWater;
			mAnimator->PlayAnimation(L"FrontGiveWater",false);

			Vector2 mousePos = Input::GetMousePosition();
			int a = 0;
		}

		//if (Input::GetKey(eKeyCode::Right)) {
		//	mState = PlayerScript::eState::Walk;
		//	mAnimator->PlayAnimation(L"RightWalk");
		//}
		//if (Input::GetKey(eKeyCode::Left)) {
		//	mState = PlayerScript::eState::Walk;
		//	mAnimator->PlayAnimation(L"LeftWalk");
		//}
		//if (Input::GetKey(eKeyCode::Up)) {
		//	mState = PlayerScript::eState::Walk;
		//	mAnimator->PlayAnimation(L"UpWalk");
		//}
		//if (Input::GetKey(eKeyCode::Down)) {
		//	mState = PlayerScript::eState::Walk;
		//	mAnimator->PlayAnimation(L"DownWalk");
		//}
	
	}
	void PlayerScript::move()
	{

		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		if (Input::GetKey(eKeyCode::Right)) {
			pos.x += 100.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::Left)) {
			pos.x -= 100.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::Up)) {
			pos.y -= 100.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::Down)) {
			pos.y += 100.0f * Time::DeltaTime();
		}

		tr->SetPosition(pos);

		if (Input::GetKeyUp(eKeyCode::Right) 
			|| Input::GetKeyUp(eKeyCode::Left) 
			|| Input::GetKeyUp(eKeyCode::Up) 
			|| Input::GetKeyUp(eKeyCode::Down)
			) {
			mState = PlayerScript::eState::Idle;
			mAnimator->PlayAnimation(L"SitDown",false);
		}
	}
	void PlayerScript::giveWater()
	{
		if (mAnimator->IsComplete()) 
		{
			mState = eState::Idle;
			mAnimator->PlayAnimation(L"Idle", false);
		}
	}
}