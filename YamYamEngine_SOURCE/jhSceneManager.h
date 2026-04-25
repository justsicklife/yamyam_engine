#pragma once
#include "CommonInclude.h"
#include "jhScene.h"

namespace jh {
	class SceneManager 
	{
	public:
		// 템플릿 타입 자바의 제네릭 같은거
		// 근데 C++ 은 타입 제약을 안걸음
		template <typename T>
		static Scene* CreateScene(const std::wstring& name) {
			T* scene = new T();
			// T 의 포인터 타입인 scene
			// SetName,Initialize 메서드가 
			// 무조건 있다고 생각함
			scene->SetName(name);
			scene->Initialize();

			// 씬 맵에 넣어줌
			mScene.insert(std::make_pair(name, scene));

			return scene;
		}

		static Scene* LoadScene(const std::wstring& name) {

			// 전에 씬이 존재한다면
			if (mActiveScene) {
				// 전에 씬 에서 나가기
				mActiveScene->OnExit();
			}

			std::map<std::wstring, Scene*>::iterator iter
				= mScene.find(name);

			// 해당하는 씬이 없으면 null 포인터 리턴
			if (iter == mScene.end())
				return nullptr;

			// iter -> second (key : value) 
			// second 는 value 를 뜻함
			mActiveScene = iter->second;

			// 현재 씬 입장
			mActiveScene->OnEnter();

			return iter->second;
		}

		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render(HDC hdc);
	private :
		//static std::vector<Scene*> mScene;
		static std::map<std::wstring, Scene*> mScene;
		static Scene* mActiveScene;
	};
}