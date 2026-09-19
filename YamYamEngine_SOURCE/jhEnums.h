#pragma once

namespace jh::enums {

	enum class eComponentType 
	{
		Transform,
		SpriteRenderer,
		Animator,
		Script,
		Camera,
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
		Animation,
		Prefab,
		End,
	};
}