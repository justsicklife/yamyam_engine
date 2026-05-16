#pragma once
#include "..\\YamYamEngine_SOURCE\\\jhMath.h"

namespace jh {
	class GridPosition {
	public:

		void SetPosition(math::Vector2 position) {
			this->position = position;
		}

		math::Vector2 GetPosition() {
			return position;
		}

	private:
		math::Vector2 position;
	};
}