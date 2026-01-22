#pragma once
#include "..\\YamYamEngine_SOURCE\\jhSceneManager.h"
#include "jhPlayScene.h"

namespace jh
{
	void LoadScenes() 
	{
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
		//SceneManager::CreateScene<EndScene>(L"PlayScene");
		//SceneManager::CreateScene<TitleScene>(L"PlayScene");

		SceneManager::LoadScene(L"PlayScene");
	}
}