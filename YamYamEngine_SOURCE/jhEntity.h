#pragma once
#include "CommonInclude.h"

namespace jh {
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