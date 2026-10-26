#pragma once
#include "..\\YamYamEngine_SOURCE\\jhResources.h"
#include "..\\YamYamEngine_SOURCE\\jhTexture.h"


namespace jh
{
	void LoadResouces()
	{
		Resources::Load<graphcis::Texture>(L"Map", L"../Resources/img/map/map_pure.png");
		Resources::Load<graphcis::Texture>(L"PacMan", L"../Resources/img/pacman/0.png");
		//Resources::Load<graphcis::Texture>(L"Chicken", L"../Resources/ChickenAlpha.bmp");
		Resources::Load<graphcis::Texture>(L"Cat", L"../Resources/Cat.bmp");
		Resources::Load<graphcis::Texture>(L"Bubble", L"../Resources/Bubble.png");
		Resources::Load<graphcis::Texture>(L"Effect", L"../Resources/MapleEffect.png");
		Resources::Load<graphcis::Texture>(L"Player", L"../Resources/Player.bmp");

	}
}	