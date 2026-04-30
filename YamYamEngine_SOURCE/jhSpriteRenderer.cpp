#include "jhSpriteRenderer.h"
#include "jhTransform.h"
#include "jhGameObject.h"

namespace jh {

	SpriteRenderer::SpriteRenderer() 
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
		
		/*Transform* tr = GetOwner()->GetComponent<Transform>();
		
		Vector2 pos = tr->GetPosition();

		Gdiplus::Graphics graphcis(hdc);
		
		graphcis.DrawImage(mImage, Gdiplus::Rect(pos.x, pos.y, mWidth, mHeight));*/

	}
	
}