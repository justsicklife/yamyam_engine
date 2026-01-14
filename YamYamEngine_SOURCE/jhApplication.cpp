#include "CommonInclude.h"
#include "jhApplication.h"
#include "jhInput.h"
#include "jhTime.h"
#include "jhMap.h"

namespace jh {

	Application::Application()
		: mHwnd(nullptr)
		, mHdc(nullptr)
		, mWidth(0)
		, mHeight(0)
		, mBackHdc(NULL)
		, mBackBitmap(NULL)

	{

	}

	Application::~Application() {

	}

	void Application::Initialize(HWND hwnd,UINT width,UINT height) {
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);

		// 사각형 구조체
		RECT rect = { 0,0,width,height };
		// 현재 윈도우의 크기가 클라이언트 영역이 되도록 크기를 조정한다.
		// (현재 윈도우 크기, 윈도우 모양 스타일, 메뉴 여부)
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		mWidth = rect.right - rect.left;
		mHeight = rect.bottom - rect.top;

		SetWindowPos(mHwnd, nullptr, 0, 0, mWidth, mHeight, 0);
		ShowWindow(mHwnd, true);

		// 윈도우 해상도에 맞는 백버퍼(도화지) 생성
		mBackBitmap = CreateCompatibleBitmap(mHdc, mWidth, mHeight);

		// 백버퍼를 가르킬 DC 생성
		mBackHdc = CreateCompatibleDC(mHdc);

		HBRUSH BlackBrush = CreateSolidBrush(RGB(0, 0, 0));

		HBRUSH oldBrush = (HBRUSH)SelectObject(mBackHdc, BlackBrush);

		HBITMAP oldBitmap = (HBITMAP)SelectObject(mBackHdc, mBackBitmap);

		mPlayer.SetPosition(0, 0);

		Map::Initailize();
		Input::Initailize();
		Time::Initailize();

	}

	void Application::Run() {
		
		Update();
		LateUpdate();
		Render();
	}

	void Application::Update() {

		Input::Update();
		Time::Update();

		mPlayer.Update();
	}

	void Application::LateUpdate() 
	{

	}

	void Application::Render() {
		Rectangle(mBackHdc, 0, 0, 1600, 900);

		Time::Render(mBackHdc);
		mPlayer.Render(mBackHdc);

		// BackBuffer 에 있는걸 원본 Buffer에 복사(그려준다)
		BitBlt(mHdc, 0, 0, mWidth, mHeight
			, mBackHdc, 0, 0, SRCCOPY);
	}
}