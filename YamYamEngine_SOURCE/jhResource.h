#pragma once
#include "jhEntity.h"

namespace jh {
	class Resource : public Entity // 추상 클래스
	{
	public:
		Resource(enums::eResourceType type);

		virtual ~Resource();

		// 순수 가상 함수 실제 메모리에 할당이 불가능해지는 문법이다.
		virtual bool Load(const std::wstring& path) = 0;

		const std::wstring& GetPath(){ return mPath; }

		void SetPath(const std::wstring& path) { mPath = path; }

	private :
		const enums::eResourceType mType;
		std::wstring mPath;
	};
}
