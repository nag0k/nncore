#pragma once

#include "d2/structures.hpp"

namespace control {
	enum class type {
		textbox = 1,
		label = 4,
		button = 6
	};

	struct position {
		int x;
		int y;
	};

	struct size {
		int x;
		int y;
	};

	enum class state {
		disabled,
		enabled
	};

	struct control {
		type type;
		state state;
		position pos;
		size size;
	};
	
	static D2::Control* find(control control);
	static bool click();
}
