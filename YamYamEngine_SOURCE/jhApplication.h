#include "CommonInclude.h"
#include "jhGameObject.h"

namespace jh {
	class Application {
	public:
		Application();
		~Application();

		void Initialize(HWND hwnd,UINT widht,UINT height);
		void Run();

		void Update();

		void LateUpdate();

		void Render();
	
	private :
		HWND mHwnd;
		HDC mHdc;

		HDC mBackHdc;
		HBITMAP mBackBitmap;

		UINT mWidth;
		UINT mHeight;

		// 플레이어
		jh::GameObject mPlayer;
	};
}