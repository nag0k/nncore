#include <windows.h>
#include "d2py_core/d2py_core.hpp"

#include <iostream>

bool WINAPI DllMain(HINSTANCE dll, DWORD reason, LPVOID reserved)
{
  switch (reason) {
  case DLL_PROCESS_ATTACH:
		DisableThreadLibraryCalls(dll);
		CreateThread(nullptr, 0, d2py_core::main, nullptr, 0, nullptr);

    break;
  case DLL_PROCESS_DETACH:
    break;
  }

  return true;
}
