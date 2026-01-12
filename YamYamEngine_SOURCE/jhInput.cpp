#include "jhInput.h"

namespace jh {
	std::vector<Input::Key> Input::Keys = {};

	int ASCII[(UINT)eKeyCode::End] =
	{
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M',
		VK_LEFT,VK_RIGHT,VK_DOWN,VK_UP,
	};

	void Input::Initailize() {
		createKeys();
	}

	void Input::Update() 
	{
		updateKeys();
	}

	// Key code 초기화
	void Input::createKeys()
	{
		for (size_t i = 0; i < (UINT)eKeyCode::End; i++)
		{
			Key key = {};
			key.bPressed = false;
			key.state = eKeyState::None;
			key.keyCode = (eKeyCode)i;

			Keys.push_back(key);
		}
	}

	// 각각 Keys 배열안에 들어있는 키를 순회해서 
	// updateKey(Key& key) 메서드를 각각실행해줌
	void Input::updateKeys()
	{
		std::for_each(Keys.begin(), Keys.end(),
			[](Key& key) -> void {
			updateKey(key);
		});
	}

	// 키가 눌렸는지 유무를 판단해서 key 값을 
	// 설정해줌 
	void Input::updateKey(Input::Key& key) {
		if (isKeyDown(key.keyCode)) 
		{
			updateKeyDown(key);
		}
		else {
			updateKeyUp(key);
		}
	}

	// 키가 눌리는 함수를 실행하고 
	// bool 값을 리턴
	bool Input::isKeyDown(eKeyCode code) {
		return GetAsyncKeyState(ASCII[(UINT)code]) & 0x8000;
	}

	// 키가 눌러지면 
	void Input::updateKeyDown(Input::Key& key) {
		// 키가 눌러진 상태라면 
		if (key.bPressed == true)
			key.state = eKeyState::Pressed;
		// 키가 처음 눌러진 상태라면
		else
			key.state = eKeyState::Down;

		key.bPressed = true;
	}

	// 키가 벗어나면
	void Input::updateKeyUp(Input::Key& key) {
		// 키를 누른상태이면
		if (key.bPressed == true)
			key.state = eKeyState::Up;
		// 키를 땐 상태이면
		else
			key.state = eKeyState::None;
	
		key.bPressed = false;
	}
}