#pragma once

#include <windows.h>
#include <string>

struct dll_module {
	const std::string name = "d2py_core.dll";
	std::string path; // use for d2py config with script lib path etc
	HMODULE handle;
};

class d2py_core {
public:
	d2py_core();
	dll_module dll;
	static DWORD WINAPI main(LPVOID param);
private:
	const std::string version = "0.0.1";
};
