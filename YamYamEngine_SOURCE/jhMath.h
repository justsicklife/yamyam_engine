#pragma once

namespace jh::math {
	struct Vector2
	{
		float y;
		float x;

		Vector2()
			: y(0.0f)
			, x(0.0f) {

		}

		Vector2(float _x, float _y)
			: y(_x)
			, x(_y)
		{
		}

		static Vector2 Lerp(Vector2 start , Vector2 target , float t) {

			return Vector2( 
				start.x * (1 - t) + target.x * t,
				start.y * (1 - t) + target.y * t);
		}
	};
}