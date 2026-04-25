#pragma once
#include "..\\YamYamEngine_SOURCE\\jhSceneManager.h"
#include "jhPlayScene.h"
#include "jhTitleScene.h"

namespace jh
{
	void LoadScenes() 
	{
		SceneManager::CreateScene<TitleScene>(L"TitleScene");
		SceneManager::CreateScene<PlayScene>(L"PlayScene");

		SceneManager::LoadScene(L"PlayScene");
	}
}