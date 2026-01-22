#include "jhApplication.h"
#include "jhInput.h"
#include "jhTime.h"
#include "jhSceneManager.h"

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

	void Application::Initialize(HWND hwnd, UINT width, UINT height) {
		adjustWindowRect(hwnd, width, height);
		createBuffer(width, height);
		initializeEtc();

		SceneManager::Initialize();
	}

	void Application::Run() {
		
		Update();
		LateUpdate();
		Render();
	}

	void Application::Update() {

		Input::Update();
		Time::Update();

		SceneManager::Update();
	}

	void Application::LateUpdate() 
	{

	}

	void Application::Render() {
		clearRenderTarget();

		Time::Render(mBackHdc);
		SceneManager::Render(mBackHdc);

		copyRenderTarget(mBackHdc,mHdc);
	}

	void Application::clearRenderTarget() {
		// clear 
		Rectangle(mBackHdc, -1, -1, 1601, 901);
	}

	void Application::copyRenderTarget(HDC source, HDC dest) {
		// BackBuffer 에 있는걸 원본 Buffer에 복사(그려준다)
		BitBlt(dest, 0, 0, mWidth, mHeight
			, source, 0, 0, SRCCOPY);
	}

	void Application::adjustWindowRect(HWND hwnd,UINT width,UINT height) {
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
	}
	
	void Application::createBuffer(UINT width, UINT height) {
		// 윈도우 해상도에 맞는 백버퍼(도화지) 생성
		mBackBitmap = CreateCompatibleBitmap(mHdc, width, height);

		// 백버퍼를 가르킬 DC 생성
		mBackHdc = CreateCompatibleDC(mHdc);

		HBITMAP oldBitmap = (HBITMAP)SelectObject(mBackHdc, mBackBitmap);
		DeleteObject(oldBitmap);
	}

	void Application::initializeEtc() {
		Input::Initailize();
		Time::Initailize();
	}

}