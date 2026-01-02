#include "jhInput.h"

namespace jh {
	std::vector<Input::Key> Input::mKeys = {};

	void Input::Initailze() {

		mKeys.resize((UINT)eKeyCode::End);

		for (size_t i = 0; i < (UINT)eKeyCode::End; i++) 
		{
			Key key = {};
			key.bPressed = false;
			key.state = eKeyState::None;
			key.keyCode = (eKeyCode)i;
		
			mKeys.push_back(key);
		}
	}

	void Input::Update() {

	}
}