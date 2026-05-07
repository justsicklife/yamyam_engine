#pragma once
#include "..\\YamYamEngine_SOURCE\\jhResources.h"
#include "..\\YamYamEngine_SOURCE\\jhTexture.h"


namespace jh
{
	void LoadResouces()
	{
		Resources::Load<graphcis::Texture>(L"Apple", L"D:/WinProj/sokoban_v2/yamyam_engine/Resources/apple.png");
		Resources::Load<graphcis::Texture>(L"Head", L"D:/WinProj/sokoban_v2/yamyam_engine/Resources/head.png");
		Resources::Load<graphcis::Texture>(L"Body", L"D:/WinProj/sokoban_v2/yamyam_engine/Resources/body.png");
	}
}	