#include "jhTexture.h"
#include "jhApplication.h"

// 해당 전역변수가 존재함을 알리는 키워드 extern
extern jh::Application application;

namespace jh::graphcis {
	Texture::Texture() 
		// 부모 도 초기화 해야지 에러 안남
		:Resource(enums::eResourceType::Textrue)
	{

	}

	Texture::~Texture()
	{
	}

	bool Texture::Load(const std::wstring& path)
	{

		std::wstring ext 
			= path.substr(path.find_last_of(L".") + 1);

		// bmp 일때
		if (ext == L"bmp")
		{
			mType = eTextureType::Bmp;
			mBitmap = (HBITMAP)LoadImageW(
				nullptr, path.c_str(), 
				IMAGE_BITMAP,
				0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

			if (mBitmap == nullptr) {
				return false;
			}

			BITMAP info = {};
			GetObject(mBitmap, sizeof(BITMAP), &info);

			mWidth = info.bmWidth;
			mHeight = info.bmHeight;

			HDC mainDC = application.GetHdc();
			// DC 새로 하나 생성
			mHdc = CreateCompatibleDC(mainDC);

			HBITMAP oldBitmap = (HBITMAP)SelectObject(mHdc, mBitmap);

			DeleteObject(oldBitmap);

		}
		else if (ext == L"png") {
			mType = eTextureType::Png;
			mImage = Gdiplus::Image::FromFile(path.c_str());
			if (mImage == nullptr) {
				return false;
			}
			mWidth = mImage->GetWidth();
			mHeight = mImage->GetHeight();

			return true;
		}

		// png 일때

		return false;
	}

}

