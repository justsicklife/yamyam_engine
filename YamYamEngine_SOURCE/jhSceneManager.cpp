#include "jhSceneManager.h"

namespace jh 
{
	std::map<std::wstring, Scene*> SceneManager::mScene = {};
	Scene* SceneManager::mActiveScene = nullptr;

	Scene* SceneManager::LoadScene(const std::wstring& name) {

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

	void SceneManager::Initialize() {
		// 실행 시점에 mActiveScene 은 nullptr 임
		//mActiveScene->Initialize();
	}

	void SceneManager::Update() {
		mActiveScene->Update();
	}

	void SceneManager::LateUpdate() {
		mActiveScene->LateUpdate();
	}

	void SceneManager::Render(HDC hdc) {
		mActiveScene->Render(hdc);
	}

	void SceneManager::FlushPendingObjects()
	{
		mActiveScene->FlushPendingObjects();
	}

}