#pragma once
#include "..\\YamYamEngine_SOURCE\\jhResources.h"
#include "..\\YamYamEngine_SOURCE\\jhTexture.h"


namespace jh
{
	void LoadResouces()
	{
		Resources::Load<graphcis::Texture>(L"BG", L"D:/WinProj/YamYamEngine/Resources/CloudOcean.png");
	}
}	