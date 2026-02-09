#include "..\\YamYamEngine_SOURCE\\\jhGameObject.h"
#include "CommonInclude.h"

namespace jh {

	using namespace std;

	enum class ObjectType {
		None,
		Baba,
		Wall,
		Text_Baba,
		Text_Is,
		Text_You,
		Text_Wall,
	};

	class Map : public GameObject {
	public:
		const int width;
		const int height;

		const int TileSize;
	
	map<ObjectType, const wchar_t*> ObjectImagePath = {
		{ ObjectType::Baba,      L"baba.png" },
		{ ObjectType::Text_You,  L"you.png" },
		{ ObjectType::Wall,      L"wall.png" },
		{ ObjectType::Text_Wall, L"text_wall.png" }
	};

	public:

		Map();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		vector<vector<ObjectType>>& GetMapArray() {
			return mapArray;
		}

		const wchar_t* GetPath() {
			return path;
		}

	private :

		vector<vector<ObjectType>> mapArray;

		const wchar_t* path = L"D:/WinProj/YamYamEngine/Resources/";
	};
}