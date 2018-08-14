#pragma once

#include "pybind11/embed.h"
#include "d2/pointers.hpp"
#include "d2/structures.hpp"
#include "d2py_core/controls.hpp"

namespace py = pybind11;

/*
	Due to pybind11 not being able to handle calling conventions
	I have to use these ugly lambda wrappers until I find a solution
*/
PYBIND11_EMBEDDED_MODULE(d2py_core, m) {
	m.def("take_screenshot", [] { take_screenshot(); });
	m.def("print_game_text", [](wchar_t *str, int color) { print_game_text(str, color); });
	m.def("exit_game", [] { exit_game(); });
	m.def("area_name", [](DWORD id) { return area_name(id); });

	py::module control = m.def_submodule("control");
	py::enum_<control::type>(control, "type")
		.value("TEXTBOX", control::type::textbox)
		.value("LABEL", control::type::label)
		.value("BUTTON", control::type::button);
}

PYBIND11_EMBEDDED_MODULE(me, m) {
	m.attr("fps") = fps;
	m.attr("ping") = ping;
}
