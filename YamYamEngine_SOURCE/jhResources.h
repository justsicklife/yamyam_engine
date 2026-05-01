#pragma once
#include "jhResource.h"

namespace jh {
	class Resources {
	public :
		template <typename T>
		static T* Find(const std::wstring& key) 
		{

			// auto 자동으로 받는 값에 자료형을 알아서 맞춰줌
			auto iter =
				mResources.find(key);

			// 찾는 리소스가 없다면 
			if (iter == mResources.end()) {
				return nullptr;
			}

			// value 반환
			return dynamic_cast<T*>(iter->second);

		}

		template <typename T>
 		static T* Load(const std::wstring& key, const std::wstring& path) {

			// T 는 Resource 의 자식 타입을 받음
			T* resource = Resources::Find<T>(key);
			// 리소스가 존재하면 리소스 반환
			if (resource != nullptr)
				return resource;

			resource = new T();
			
			if (!resource->Load(path)) {
				assert(false);
			}

			resource->SetName(key);
			resource->SetPath(path);
			// make_pair 두개의 자료형을 묶은것
			mResources.insert(std::make_pair(key, resource));

			return resource;

		}

	private:
		static std::map<std::wstring, Resource*> mResources;
	};
}