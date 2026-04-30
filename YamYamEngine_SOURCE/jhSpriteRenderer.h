#pragma once
#include "jhComponent.h"
#include "jhEntity.h"
#include <gdiplus.h>

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

	private :
		
	};
}