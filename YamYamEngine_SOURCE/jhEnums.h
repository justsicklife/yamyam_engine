#pragma once

namespace jh::enums {

	enum class eComponentType 
	{
		Transform,
		SpriteRenderer,
		Script,
		End,
	};

	enum class eLayerType {
		None,
		BackGround,
		// Tree
		// character
		Player,
		Max = 16,
	};

	enum class eResourceType {
		Textrue,
		AudioClip,
		Prefab,
		End,
	};
}