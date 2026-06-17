#pragma once
#include "..\\YamYamEngine_SOURCE\\jhResources.h"
#include "..\\YamYamEngine_SOURCE\\jhTexture.h"


namespace jh
{
	void LoadResouces()
	{
		Resources::Load<graphcis::Texture>(L"Map", L"D:../Resources/img/map/map_pure.png");
		Resources::Load<graphcis::Texture>(L"PacMan", L"../Resources/img/pacman/0.png");
	}
}	