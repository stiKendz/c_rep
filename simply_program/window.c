#include <windows.h>

/* int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int mCmdShow)
{
	MessageBox(NULL, "Привет мир (снова)", "Окошко с текстом", MB_OK);
	return 0;
}
*/

const char g_szClassName[] = "мойОконныйКласс"; /* переменная, хранящая название окна и используемая в дальнейшем для регистрации -
класса Window в системе */

// Это 4й шаг
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch(msg)
	{
		case WM_CLOSE:
			DestroyWindow(hwnd);
		break;
		case WM_DESTROY:
			PostQuitMessage(0);
		break;
		default: 
			return DefWindowProc(hwnd, msg, wParam, lParam);
	}
	return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, // Точка входа программы Windows
LPSTR plCmdLine, int nCmdShow)
{ /* Код исользуемый для регистрации класса окна в системе.
	Мы заполняем элементы структуры WNDCLASSEX и вызываем RegisterClassEx()*/
	WNDCLASSEX wc;
	HWND hwnd;
	MSG Msg;

	// 1й шаг - регистрация класса окна
	wc.cbSize 			= sizeof(WNDCLASSEX); // Размер структуры
	wc.style 			= 0; // Стили классов (_CS)
	wc.lpfnWndProc 		= WndProc; // Указатель на процедуру окна для этого класса Window
	wc.cbClsExtra 		= 0; // Объем дополнительных данных, выделенных для этого класса в памяти. Обычно 0.
	wc.cbWndExtra 		= 0; // Количество дополнительных данных, выделяемых в памяти для каждого окна такого типа. Обычно 0.
	wc.hInstance 		= hInstance; // Дескриптор экземпляра приложения (получили в первом параметре WinMain).
	wc.hIcon 			= LoadIcon(NULL, IDI_APPLICATION); /* Большой значок (обычно 32x32) отображается, 
	когда пользователь нажимает Alt+Tab. */
	wc.hCursor 			= LoadCursor(NULL, IDC_ARROW); // Курсор, который будет отображаться над окном.
	wc.hbrBackground 	= (HBRUSH)(COLOR_WINDOW + 1); // Фоновая кисть для задания цвета окна.
	wc.lpszMenuName		= NULL; // Имя ресурса меню, который будет использоваться для окон с этим классом.
	wc.lpszClassName 	= g_szClassName; // Имя, с помощью которого можно идентифицировать класс.
	wc.hIconSm			= LoadIcon(NULL, IDI_APPLICATION); /* Маленький (обычно 16х16) значок, 
	отображаемый на панели задач и в левом верхнем углу окна. */

	if(!RegisterClassEx(&wc))
	{
		MessageBox(NULL, "Регистрация окна провалена!", "Ошибка", MB_ICONEXCLAMATION | MB_OK);
		return 0;
	}

	// 2й шаг - сощдание самого окна
	hwnd = CreateWindowEx(
		WS_EX_CLIENTEDGE, // Стиль окна, который указывает на рамку с утопленным краем
		g_szClassName,
		"Заголовок моего окна",
		WS_OVERLAPPEDWINDOW, // Один из параметров стиля окна
		CW_USEDEFAULT, CW_USEDEFAULT, 300, 200,
		NULL, NULL, hInstance, NULL);

	if(hwnd == NULL)
	{
		MessageBox(NULL, "Создание окна провалилось", "Ошибка", MB_ICONEXCLAMATION | MB_OK);
		return 0;
	}

	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	// 3й шаг - цикл сообщений
	while(GetMessage(&Msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	}

	return Msg.wParam;
}









