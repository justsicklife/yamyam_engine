#include "jhTime.h"

namespace jh {
	// 초당 몇번 카운터가 증가하는지 (CPU 타이머 주파수)
	LARGE_INTEGER Time::CpuFrequency = {};
	// 이전 프레임의 카운터 값
	LARGE_INTEGER Time::PrevFrequency = {};
	// 현재 프레임의 카운터 값
	LARGE_INTEGER Time::CurrentFrequency = {};
	// 이전 프레임과 현재 프레임 사이의 시간 (초 단위)
	float Time::DeltaTimeValue = 0.0f;


	// CPU 타이머 주파수 저장
	// 첫 프레임 기준 시간 설정
	void Time::Initailize() {

		// 1 초에 카운터 수치
		QueryPerformanceFrequency(&CpuFrequency);

		// 현재 카운터 값
		QueryPerformanceCounter(&PrevFrequency);

	}

	void Time::Update() {
		// 현재 카운터 값
		QueryPerformanceCounter(&CurrentFrequency);

		// 현재 카운터 - 이전 카운터 = differenceFrequency
		float differenceFrequency
			= static_cast<float>(CurrentFrequency.QuadPart - PrevFrequency.QuadPart);
		
		//  델타타임 = 카운터 차이 / 1 초 카운터 수치 
		DeltaTimeValue = differenceFrequency / static_cast<float>(CpuFrequency.QuadPart);
		PrevFrequency.QuadPart = CurrentFrequency.QuadPart;
	}

	void Time::Render(HDC hdc) {
		static float time = 0.0f;
	
		
		time += DeltaTimeValue;
		// 프레임수 = 1 / 델타타임
		float fps = 1.0f / DeltaTimeValue;

		wchar_t str[50] = L"";

		swprintf_s(str, 50, L"Time : %d", (int)fps);

		int len = wcsnlen_s(str,50);

		TextOut(hdc, 0, 0, str, len);
	}
}