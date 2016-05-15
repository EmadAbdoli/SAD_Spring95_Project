#include "console.h"

void RedirectIOToConsole()
{
	AllocConsole();
	HANDLE stdHandle;
	int hConsole;
	FILE* fp;
	stdHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	hConsole = _open_osfhandle((long)stdHandle, _O_TEXT);
	fp = _fdopen(hConsole, "w");

	freopen_s(&fp, "CONOUT$", "w", stdout);
/*
	int hConHandle;
	HANDLE lStdHandle;

	CONSOLE_SCREEN_BUFFER_INFO coninfo;

	FILE *fp;

	// allocate a console for this app

	if (!AllocConsole()) return;

	// set the screen buffer to be big enough to let us scroll text

	if (!GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &coninfo)) return;

	coninfo.dwSize.Y = MAX_CONSOLE_LINES;

	if (!SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), coninfo.dwSize)) return;

	// redirect unbuffered STDOUT to the console

	lStdHandle = GetStdHandle(STD_OUTPUT_HANDLE);

	if (lStdHandle == INVALID_HANDLE_VALUE)
		return;

	hConHandle = _open_osfhandle((long)lStdHandle, _O_TEXT);

	if (hConHandle == -1)
		return;

	fp = _fdopen( hConHandle, "w" );

	if (fp == nullptr)
		return;

	*stdout = *fp;

	setvbuf( stdout, NULL, _IONBF, 0 );

	// redirect unbuffered STDIN to the console

	lStdHandle = GetStdHandle(STD_INPUT_HANDLE);

	if (lStdHandle == INVALID_HANDLE_VALUE)
		return;

	hConHandle = _open_osfhandle((long)lStdHandle, _O_TEXT);

	if (hConHandle == -1)
		return;

	fp = _fdopen( hConHandle, "r" );

	if (fp == nullptr)
		return;

	*stdin = *fp;

	setvbuf( stdin, NULL, _IONBF, 0 );

	// redirect unbuffered STDERR to the console

	lStdHandle = GetStdHandle(STD_ERROR_HANDLE);

	if (lStdHandle == INVALID_HANDLE_VALUE)
		return;

	hConHandle = _open_osfhandle((long)lStdHandle, _O_TEXT);

	if (hConHandle == -1)
		return;

	fp = _fdopen( hConHandle, "w" );

	*stderr = *fp;

	setvbuf( stderr, NULL, _IONBF, 0 );

	// make cout, wcout, cin, wcin, wcerr, cerr, wclog and clog 

	// point to console as well

	std::ios::sync_with_stdio();
	*/
}
