#include "d2py_core/d2py_core.hpp"
#include "d2py_core/bindings.hpp"

//#include <nlohmann/json.hpp>

//using json = nlohmann::json;

DWORD WINAPI d2py_core::main(LPVOID param) {
	FILE* new_stdout;
	AllocConsole();
	freopen_s(&new_stdout, "CONOUT$", "w", stdout);

	d2py_core d2py;

	py::scoped_interpreter python{};

	py::eval_file(d2py.dll.path + "/main.py" , py::globals());

	return true;
}

d2py_core::d2py_core()
{
	dll.handle = GetModuleHandle(dll.name.c_str());

	char buf[MAX_PATH];
	GetModuleFileName(dll.handle, buf, MAX_PATH);
	std::string full_path(buf);

	dll.path = full_path.substr(0, full_path.find_last_of("/\\"));
}
