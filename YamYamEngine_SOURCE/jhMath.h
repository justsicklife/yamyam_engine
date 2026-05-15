#pragma once

namespace jh::math {
	struct Vector2
	{
		static Vector2 One;
		static Vector2 Zero;

		float x;
		float y;

		Vector2()
			: x(0.0f)
			, y(0.0f) {

		}

		Vector2(float _x, float _y)
			: x(_x)
			, y(_y)
		{
		}

		bool operator==(const Vector2& vector2) const {
			if (this->x == vector2.x && this->y == vector2.y) {
				return true;
			}

			return false;
		}
	};
}