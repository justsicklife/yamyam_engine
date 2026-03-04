#include "jhResources.h"

namespace jh {

	map<ObjectType, const wstring> Resources::ObjectImagePath = {
		{ ObjectType::Baba,      L"baba.png" },
		{ ObjectType::Text_You,  L"you.png" },
		{ ObjectType::Wall,      L"wall.png" },
		{ ObjectType::Text_Wall, L"text_wall.png" }
	};

	const wstring Resources::path = L"D:/WinProj/YamYamEngine/Resources/";
}