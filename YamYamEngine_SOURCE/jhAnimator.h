#pragma once
#include "jhComponent.h"
#include "jhAnimation.h"

namespace jh {
	/// <summary>
	/// Animator 는 Animation 을 map 형태로 가지고있는 클래스
	/// </summary>
	class Animator : public Component
	{
	public:
		Animator();
		~Animator();

		 void Initialize() override;
		 void Update() override;
		 void LateUpdate() override;
		 void Render(HDC hdc) override;

		 void CreateAnimation(
			 const std::wstring& name,
			 graphcis::Texture* spriteSheet,
			 Vector2 leftTop,
			 Vector2 size,
			 Vector2 offset,
			 UINT spriteLength,
			 float duration
		 );
		 
		 Animation* FindAnimation(const std::wstring& name);
		 void PlayAnimation(const std::wstring& name,bool loop = true);

		 //PlayAnimation(L"move", false);	

	private:
		// 애니메이션을 map 으로 가지고있는 변수
		std::map<std::wstring, Animation*> mAnimations;
		// 선택된 애니메이션		
		Animation* mActiveAnimation;
		bool mbLoop;
	};
}

