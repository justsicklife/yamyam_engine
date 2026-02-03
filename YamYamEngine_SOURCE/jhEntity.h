#pragma once
#include "CommonInclude.h"

namespace jh {
	// 엔진 안에서 관리되는 모든 객체의 최소 단위
	class Entity {
	public:
		Entity();
		virtual ~Entity();

		void SetName(const std::wstring& name) { mName = name; }
		std::wstring& GetName() { return mName; }
	private:
		// 2 byte 캐릭터 (한글도 올수있음)
		std::wstring mName;
	};
}