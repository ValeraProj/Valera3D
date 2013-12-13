#ifndef _V3D_KEY_CODES_H_
#define _V3D_KEY_CODES_H_

namespace v3d
{
	enum EModifierCode 
	{
		Modifier_Uknown = 0x00,
		Modifier_Ctrl   = 0x01,
		Modifier_Alt    = 0x02,
		Modifier_Shift  = 0x04
	};

	enum EKeyCode
	{
		eKey_Uknown           = 0x00,  // Default
		eKey_LButton          = 0x01,  // Left mouse button
		eKey_RButton          = 0x02,  // Right mouse button
		eKey_Cancel           = 0x03,  // Control-break processing
		eKey_MButton          = 0x04,  // Middle mouse button (three-button mouse)
		eKey_XButton1         = 0x05,  // Windows 2000/XP: X1 mouse button
		eKey_XButton2         = 0x06,  // Windows 2000/XP: X2 mouse button
		eKey_Back             = 0x08,  // BACKSPACE key
		eKey_Tab              = 0x09,  // TAB key
		eKey_Clear            = 0x0C,  // CLEAR key
		eKey_Return           = 0x0D,  // ENTER key
		eKey_Shift            = 0x10,  // SHIFT key
		eKey_Control          = 0x11,  // CTRL key
		eKey_Menu             = 0x12,  // ALT key
		eKey_Pause            = 0x13,  // PAUSE key
		eKey_Capital          = 0x14,  // CAPS LOCK key
		eKey_Kana             = 0x15,  // IME Kana mode
		eKey_Hanguel          = 0x15,  // IME Hanguel mode (maintained for compatibility use KEY_HANGUL)
		eKey_Hangul           = 0x15,  // IME Hangul mode
		eKey_Junja            = 0x17,  // IME Junja mode
		eKey_Final            = 0x18,  // IME final mode
		eKey_Hanja            = 0x19,  // IME Hanja mode
		eKey_Kanji            = 0x19,  // IME Kanji mode
		eKey_Escape           = 0x1B,  // ESC key
		eKey_Convert          = 0x1C,  // IME convert
		eKey_Nonconvert       = 0x1D,  // IME nonconvert
		eKey_Accept           = 0x1E,  // IME accept
		eKey_Modechange       = 0x1F,  // IME mode change request
		eKey_Space            = 0x20,  // SPACEBAR
		eKey_Prior            = 0x21,  // PAGE UP key
		eKey_Next             = 0x22,  // PAGE DOWN key
		eKey_End              = 0x23,  // END key
		eKey_Home             = 0x24,  // HOME key
		eKey_Left             = 0x25,  // LEFT ARROW key
		eKey_Up               = 0x26,  // UP ARROW key
		eKey_Right            = 0x27,  // RIGHT ARROW key
		eKey_Down             = 0x28,  // DOWN ARROW key
		eKey_Select           = 0x29,  // SELECT key
		eKey_Print            = 0x2A,  // PRINT key
		eKey_Execut           = 0x2B,  // EXECUTE key
		eKey_Snapshot         = 0x2C,  // PRINT SCREEN key
		eKey_Insert           = 0x2D,  // INS key
		eKey_Delete           = 0x2E,  // DEL key
		eKey_Help             = 0x2F,  // HELP key
		eKey_Key_0            = 0x30,  // 0 key
		eKey_Key_1            = 0x31,  // 1 key
		eKey_Key_2            = 0x32,  // 2 key
		eKey_Key_3            = 0x33,  // 3 key
		eKey_Key_4            = 0x34,  // 4 key
		eKey_Key_5            = 0x35,  // 5 key
		eKey_Key_6            = 0x36,  // 6 key
		eKey_Key_7            = 0x37,  // 7 key
		eKey_Key_8            = 0x38,  // 8 key
		eKey_Key_9            = 0x39,  // 9 key
		eKey_Key_A            = 0x41,  // A key
		eKey_Key_B            = 0x42,  // B key
		eKey_Key_C            = 0x43,  // C key
		eKey_Key_D            = 0x44,  // D key
		eKey_Key_E            = 0x45,  // E key
		eKey_Key_F            = 0x46,  // F key
		eKey_Key_G            = 0x47,  // G key
		eKey_Key_H            = 0x48,  // H key
		eKey_Key_I            = 0x49,  // I key
		eKey_Key_J            = 0x4A,  // J key
		eKey_Key_K            = 0x4B,  // K key
		eKey_Key_L            = 0x4C,  // L key
		eKey_Key_M            = 0x4D,  // M key
		eKey_Key_N            = 0x4E,  // N key
		eKey_Key_O            = 0x4F,  // O key
		eKey_Key_P            = 0x50,  // P key
		eKey_Key_Q            = 0x51,  // Q key
		eKey_Key_R            = 0x52,  // R key
		eKey_Key_S            = 0x53,  // S key
		eKey_Key_T            = 0x54,  // T key
		eKey_Key_U            = 0x55,  // U key
		eKey_Key_V            = 0x56,  // V key
		eKey_Key_W            = 0x57,  // W key
		eKey_Key_X            = 0x58,  // X key
		eKey_Key_Y            = 0x59,  // Y key
		eKey_Key_Z            = 0x5A,  // Z key
		eKey_LWin             = 0x5B,  // Left Windows key (Microsoft� Natural� keyboard)
		eKey_RWin             = 0x5C,  // Right Windows key (Natural keyboard)
		eKey_Apps             = 0x5D,  // Applications key (Natural keyboard)
		eKey_Sleep            = 0x5F,  // Computer Sleep key
		eKey_Numpad0          = 0x60,  // Numeric keypad 0 key
		eKey_Numpad1          = 0x61,  // Numeric keypad 1 key
		eKey_Numpad2          = 0x62,  // Numeric keypad 2 key
		eKey_Numpad3          = 0x63,  // Numeric keypad 3 key
		eKey_Numpad4          = 0x64,  // Numeric keypad 4 key
		eKey_Numpad5          = 0x65,  // Numeric keypad 5 key
		eKey_Numpad6          = 0x66,  // Numeric keypad 6 key
		eKey_Numpad7          = 0x67,  // Numeric keypad 7 key
		eKey_Numpad8          = 0x68,  // Numeric keypad 8 key
		eKey_Numpad9          = 0x69,  // Numeric keypad 9 key
		eKey_Multiply         = 0x6A,  // Multiply key
		eKey_Add              = 0x6B,  // Add key
		eKey_Separator        = 0x6C,  // Separator key
		eKey_Subtract         = 0x6D,  // Subtract key
		eKey_Decimal          = 0x6E,  // Decimal key
		eKey_Divide           = 0x6F,  // Divide key
		eKey_F1               = 0x70,  // F1 key
		eKey_F2               = 0x71,  // F2 key
		eKey_F3               = 0x72,  // F3 key
		eKey_F4               = 0x73,  // F4 key
		eKey_F5               = 0x74,  // F5 key
		eKey_F6               = 0x75,  // F6 key
		eKey_F7               = 0x76,  // F7 key
		eKey_F8               = 0x77,  // F8 key
		eKey_F9               = 0x78,  // F9 key
		eKey_F10              = 0x79,  // F10 key
		eKey_F11              = 0x7A,  // F11 key
		eKey_F12              = 0x7B,  // F12 key
		eKey_F13              = 0x7C,  // F13 key
		eKey_F14              = 0x7D,  // F14 key
		eKey_F15              = 0x7E,  // F15 key
		eKey_F16              = 0x7F,  // F16 key
		eKey_F17              = 0x80,  // F17 key
		eKey_F18              = 0x81,  // F18 key
		eKey_F19              = 0x82,  // F19 key
		eKey_F20              = 0x83,  // F20 key
		eKey_F21              = 0x84,  // F21 key
		eKey_F22              = 0x85,  // F22 key
		eKey_F23              = 0x86,  // F23 key
		eKey_F24              = 0x87,  // F24 key
		eKey_Numlock          = 0x90,  // NUM LOCK key
		eKey_Scroll           = 0x91,  // SCROLL LOCK key
		eKey_LShift           = 0xA0,  // Left SHIFT key
		eKey_RShift           = 0xA1,  // Right SHIFT key
		eKey_LControl         = 0xA2,  // Left CONTROL key
		eKey_RControl         = 0xA3,  // Right CONTROL key
		eKey_LMenu            = 0xA4,  // Left MENU key
		eKey_RMenu            = 0xA5,  // Right MENU key
		eKey_Plus             = 0xBB,  // Plus Key   (+)
		eKey_Comma            = 0xBC,  // Comma Key  (,)
		eKey_Minus            = 0xBD,  // Minus Key  (-)
		eKey_Period           = 0xBE,  // Period Key (.)
		eKey_Attn             = 0xF6,  // Attn key
		eKey_CrSel            = 0xF7,  // CrSel key
		eKey_ExSel            = 0xF8,  // ExSel key
		eKey_ErEof            = 0xF9,  // Erase EOF key
		eKey_Play             = 0xFA,  // Play key
		eKey_Zoom             = 0xFB,  // Zoom key
		eKey_PA1              = 0xFD,  // PA1 key
		eKey_Oem_Clear        = 0xFE,  // Clear key
		
		eKey_Codes_Count      = 0xFF   // Count
	};
}

#endif