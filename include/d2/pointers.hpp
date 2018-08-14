#pragma once

#include <type_traits>

#include "d2/structures.hpp"

#define FN(name, type, address)		\
  auto name = reinterpret_cast<std::add_pointer_t<type>>(address);

#define VAR(name, type, address)	\
	auto name = std::add_pointer_t<type>(address);

FN(take_screenshot, void __fastcall (), 0x4FA7A0)
FN(print_game_text, void __fastcall(wchar_t *str, int color), 0x49E3A0)
FN(exit_game, void __fastcall (), 0x44DD60)
FN(area_name, wchar_t* __fastcall (DWORD id), 0x453E70)

VAR(fps, DWORD, 0x7BB390)
VAR(ping, DWORD, 0x7A04A4)

// controls are a linked list
VAR(first_control, D2::Control*, 0x7D55BC)
