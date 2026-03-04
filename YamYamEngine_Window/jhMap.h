#include "..\\YamYamEngine_SOURCE\\\jhGameObject.h"
#include "CommonInclude.h"
#include "jhEnums.h"

namespace jh {

	using namespace std;

	class Map : public GameObject {
	public:
		const int width;
		const int height;

		const int TileSize;

	public:

		Map();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		vector<vector<ObjectType>>& GetMapArray() {
			return mapArray;
		}

	private :
		vector<vector<ObjectType>> mapArray;
	};
}