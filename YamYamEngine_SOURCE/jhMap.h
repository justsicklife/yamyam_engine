#include "CommonInclude.h"
#pragma once

namespace jh {

	enum class Object {
		Rock,Flag,Box,Player,None
	};

	class Map {
	public :
		static void Initailize();
		static void Update();
	private :
		//std::vector<std::vector<Object>> tiles;
		static Object** Tiles;
	};
}