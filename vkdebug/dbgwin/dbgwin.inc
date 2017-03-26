TB_PIN          equ 129
TB_CLEAR        equ 130
TB_HELP         equ 131
TB_OPEN         equ 132
TB_SAVE         equ 133

DEFAULT_WIDTH   equ 250
DEFAULT_HEIGHT  equ 250
TB_HEIGHT       equ 27
PIN_ON          equ 5
PIN_OFF         equ 4
DEBUG_EDIT      equ 1102

IDM_SELALL      equ 1103
IDM_HELP        equ 1104

HANDLE_TB_OPEN          proto :dword, :dword, :dword
HANDLE_TB_PIN           proto :dword, :dword, :dword
HANDLE_TB_HELP          proto :dword, :dword, :dword
HANDLE_TB_SAVE          proto :dword, :dword, :dword
HANDLE_TB_CLEAR         proto :dword, :dword, :dword
HANDLE_WM_INITDIALOG    proto :dword, :dword, :dword
HANDLE_WM_CREATE        proto :dword, :dword, :dword
HANDLE_WM_DESTROY       proto :dword, :dword, :dword
HANDLE_WM_SIZE          proto :dword, :dword, :dword
HANDLE_WM_COMMAND       proto :dword, :dword, :dword
HANDLE_WM_NOTIFY        proto :dword, :dword, :dword

WinMain                 proto :dword, :dword, :dword, :dword

