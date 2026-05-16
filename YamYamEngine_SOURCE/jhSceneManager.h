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
		static Scene* CreateScene(const std::wstring& name)
		{
			T* scene = new T();
			// T 의 포인터 타입인 scene
			// SetName,Initialize 메서드가 
			// 무조건 있다고 생각함
			scene->SetName(name);

			mActiveScene = scene;

			scene->Initialize();

			// 씬 맵에 넣어줌
			mScene.insert(std::make_pair(name, scene));

			return scene;
		}

		static Scene* LoadScene(const std::wstring& name);

		static Scene* GetActiveScene() { return mActiveScene; }

		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render(HDC hdc);
		static void FlushPendingObjects();

	private :
		//static std::vector<Scene*> mScene;
		static std::map<std::wstring, Scene*> mScene;
		static Scene* mActiveScene;
	};
}