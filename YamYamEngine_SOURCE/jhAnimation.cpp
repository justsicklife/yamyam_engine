#include "jhAnimation.h"
#include "jhTime.h"

namespace jh {
	Animation::Animation()
		: Resource(enums::eResourceType::Animation),
		mAnimator(nullptr),
		mTexture(nullptr),
		mAnimationSheet{},
		mIndex(-1),
		mTime(0.0f),
		mbComplete(false)
	{
	}

	void Animation::Update() {
		if (mbComplete)
			return;

		mTime += Time::DeltaTime();

		if (mAnimationSheet[mIndex].duration < mTime) {
			if (mIndex < mAnimationSheet.size() - 1) {
				mIndex++;
			}
			else {
				mbComplete = true;
			}
		}
	}

	void Animation::Render(HDC hdc) {

	}

	Animation::~Animation()
	{
	}

	void Animation::CreateAnimation(
		const std::wstring& name,
		graphcis::Texture* spriteSheet,
		Vector2 leftTop,
		Vector2 size,
		Vector2 offset,
		UINT spriteLength,
		float duration
	) {

	}

	void Animation::Reset() {
		mTime = 0.0f;
		mIndex = 0;
		mbComplete = false;
	}

	bool Animation::Load(const std::wstring& path)
	{
		return false;
	}
}
