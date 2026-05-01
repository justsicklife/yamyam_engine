#pragma once
#include "jhComponent.h"
#include "jhEntity.h"
#include "jhTexture.h"

namespace jh {
	
	class SpriteRenderer : public Component
	{
	public :
		SpriteRenderer();
		~SpriteRenderer();

		void Initialize() override;
		void Update()  override;
		void LateUpdate()  override;
		void Render(HDC hdc)  override;

		void SetTexture(graphcis::Texture* texture) {
			mTexture = texture;
		}

		void SetSize(jh::math::Vector2 size) { mSize = size; }

	private :
		graphcis::Texture* mTexture;
		jh::math::Vector2 mSize;
	};
}