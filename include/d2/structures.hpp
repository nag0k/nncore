#pragma once

#include <Windows.h>

// Taken from D2BS

namespace D2 {
	struct ControlText // size = 0x20
	{
		wchar_t* wText[5]; //0x00 for each field
		DWORD dwColor;	//0x14
		DWORD dwAlign;	//0x18
		ControlText* pNext;	//0x1C
	};

	struct Control
	{
		DWORD dwType;					//0x00
		DWORD *_1;						//0x04 // unsure? definitely a ptr but not obvious, usually points to 6 when dwType is 6 I think
		DWORD dwDisabled;				//0x08
		DWORD dwPosX;					//0x0C
		DWORD dwPosY;					//0x10
		DWORD dwSizeX;					//0x14
		DWORD dwSizeY;					//0x18
		DWORD *_2;						//0x1C // some sort of function (maybe click?)
		DWORD _3;						//0x20
		DWORD *_4;						//0x24 // some sort of function
		DWORD *_5;						//0x28
		DWORD _6;						//0x2C
		DWORD *_7;						//0x30 // ptr to something...
		DWORD *_8;						//0x34 // another random ptr... mostly dead ends when I examined them
		DWORD _9;						//0x38
		Control* pNext;					//0x3C
		DWORD _10;						//0x40
		DWORD unkState; 					//0x44 _11 0 when button avail to be clicked 1 when greyed - still need to look at this more
		ControlText* pFirstText;			//0x48
		ControlText* pLastText;			//0x4C
		ControlText* pSelectedText;		//0x50
		DWORD dwSelectEnd;				//0x54
		DWORD dwSelectStart;				//0x58
		union {
			struct { //Textboxes
				wchar_t wText[256];		//0x5C
				DWORD dwCursorPos;
				DWORD dwIsCloaked;
			};
			struct { //Buttons
				DWORD _12[2];			//0x5C
				wchar_t wText2[256];	//0x6C
			};
		};
	};
}
