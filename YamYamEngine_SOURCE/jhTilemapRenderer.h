#pragma once
#include "jhGameObject.h"

namespace jh {
	// 타일맵을 그려주는 컴포넌트
	class TilemapRenderer : public Component
	{
	public:

		TilemapRenderer();
		~TilemapRenderer();

		void Initialize() override;
		void Update()  override;
		void LateUpdate()  override;
		void Render(HDC hdc)  override;

	private:
	};
}