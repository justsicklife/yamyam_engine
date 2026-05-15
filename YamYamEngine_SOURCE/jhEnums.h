#pragma once

namespace jh::enums {
	enum class eLayerType {
		None,
		BackGround,
		// Tree
		// character
		Player,
		Max = 4,
		//Max = 16,
	};

	enum class eResourceType {
		Textrue,
		AudioClip,
		Prefab,
		End,
	};
}