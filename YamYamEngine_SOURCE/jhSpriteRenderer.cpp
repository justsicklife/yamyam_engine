#include "jhSpriteRenderer.h"
#include "jhTransform.h"
#include "jhGameObject.h"
#include "jhTexture.h"

namespace jh {

	SpriteRenderer::SpriteRenderer() 
		: 
		Component(),
		mSize(Vector2::One),
		mTexture(nullptr)
	{
	}
	SpriteRenderer::~SpriteRenderer()
	{
	}
	void SpriteRenderer::Initialize()
	{
	}
	void SpriteRenderer::Update()
	{
	}
	void SpriteRenderer::LateUpdate()
	{
	}

	void SpriteRenderer::Render(HDC hdc)
	{
		
		// 텍스쳐 세팅 해주세요 !
		if (mTexture == nullptr) {
			assert(false);
		}



		Transform* tr = GetOwner()->GetComponent<Transform>();
		
		Vector2 pos = tr->GetPosition();

		if (mTexture->GetTextureType()
			== graphcis::Texture::eTextureType::Bmp) {
			TransparentBlt(
				hdc,
				pos.x,
				pos.y,
				mTexture->GetWidth() * mSize.x,
				mTexture->GetHeight() * mSize.y,
				mTexture->GetHdc(), 0, 0,
				mTexture->GetWidth(),
				mTexture->GetHeight(),
				RGB(255, 0, 255)
			);
		} 
		else if (mTexture->GetTextureType()
			== graphcis::Texture::eTextureType::Png) {
			Gdiplus::Graphics graphcis(hdc);

			// 고품질 보간 모드 설정
			graphcis.SetInterpolationMode(Gdiplus::InterpolationModeNearestNeighbor);

			graphcis.DrawImage(mTexture->GetImage()
				, Gdiplus::Rect(pos.x, pos.y,
					mTexture->GetWidth() * mSize.x,
					mTexture->GetHeight() * mSize.y
				));
		}

	}
	
}