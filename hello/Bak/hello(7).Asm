.386 
.model flat, stdcall 
option casemap:none ; otkluchaet chuvstvitelnost k registru (hello and Hello razniye)

include \masm32\include\windows.inc ;WinAPI
include \masm32\include\kernel32.inc ;vazhnaya biblioteka dlya upravleniya memory, processami, vvod, vivod i td;
include \masm32\include\user32.inc ;dlya upravleniya GUI;
includelib \masm32\lib\kernel32.lib ;ukazivayet komponovschiku ispolzovat etu biblioteku dlya razresheniya vneshnikh ssilok na functsii iz kernel32.dll
includelib \masm32\lib\user32.lib ;ukazivayet komponovschiku ispolzovat etu biblioteku dlya razresheniya vneshnikh ssilok na functsii iz user32.dll

.data ;opredeleniye peremennikh
WindowName db "Hello World Window", 0 ;db - define byte  ;0 - nulterminirovannaya string
HelloMessage db "Hello World", 0

.data?
hInstance HINSTANCE ? ;descriptor ekzemplyara, vkhoda v prilozheniye

.code ;section ispolnyaemogo koda
start: ;tockha starta programmi
	invoke GetModuleHandle, NULL
	mov hInstance, eax
	
	invoke MessageBox, NULL, addr HelloMessage, addr WindowName, MB_OK
	
	invoke ExitProcess, 0
end start