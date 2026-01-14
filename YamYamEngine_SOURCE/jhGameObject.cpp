#include "jhGameObject.h"
#include "jhInput.h"
#include "jhTime.h"
#include <gdiplus.h>

using namespace Gdiplus;

#pragma comment(lib,"Gdiplus.lib")

ULONG_PTR gdiplusToken;

GdiplusStartupInput gdiplusStartupInput;

namespace jh 
{
	GameObject::GameObject():
		mX(0),
		mY(0){

	}

	GameObject::~GameObject() {

	}

	void GameObject::Update() {
		
		const int speed = 100.0f;

		if (Input::GetKey(eKeyCode::A)) {
			mX -= speed * Time::DeltaTime();
		}

		if (Input::GetKey(eKeyCode::D)) {
			mX += speed * Time::DeltaTime();
		}

		if (Input::GetKey(eKeyCode::W)) {
			mY -= speed * Time::DeltaTime();
		}

		if (Input::GetKey(eKeyCode::S)) {
			mY += speed * Time::DeltaTime();
		}
	}

	void GameObject::LateUpdate() {

	}

	void GameObject::Render(HDC hdc) {

		GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

		Graphics graphics(hdc);
		Image image(L"Resources/baba.png");
		graphics.DrawImage(&image, 24+mX, 24+mY);

		//Rectangle(hdc, 50 + mX,  50 + mY, 100 + mX, 100 + mY);
	}
}