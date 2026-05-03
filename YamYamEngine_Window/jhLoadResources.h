#pragma once
#include "..\\YamYamEngine_SOURCE\\jhResources.h"
#include "..\\YamYamEngine_SOURCE\\jhTexture.h"


namespace jh
{
	void LoadResouces()
	{
		Resources::Load<graphcis::Texture>(L"Apple", L"D:/WinProj/sokoban_v2/yamyam_engine/Resources/apple.png");
		Resources::Load<graphcis::Texture>(L"tile_odd", L"D:/WinProj/sokoban_v2/yamyam_engine/Resources/tile_odd.png");
		Resources::Load<graphcis::Texture>(L"tile_even", L"D:/WinProj/sokoban_v2/yamyam_engine/Resources/tile_even.png");
	}
}	