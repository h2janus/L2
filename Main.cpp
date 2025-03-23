#define _WIN32_WINNT _WIN32_WINNT_WINXP
#define NOMINMAX
#include <windows.h>
#include <cstdlib>

// Start L2 as .bin with IP as parameter.
// You can use IP or DNS as IP parameter.
// You could include other parameters.
// You can change the path to the .bin file to avoid including the L2.exe inside the System folder.
// Author: Zoey76
int _stdcall wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nShowCmd) {

    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory( &si, sizeof(si) );
    si.cb = sizeof(si);
    ZeroMemory( &pi, sizeof(pi) );

    CreateProcess(L"l2.bin",     // Module name
        L"l2.bin IP=127.0.0.1",  // Command line
        NULL,                    // Process handle not inheritable
        NULL,                    // Thread handle not inheritable
        FALSE,                   // Set handle inheritance to FALSE
        0,                       // No creation flags
        NULL,                    // Use parent's environment block
        NULL,                    // Use parent's starting directory 
        &si,                     // Pointer to STARTUPINFO structure
        &pi );                   // Pointer to PROCESS_INFORMATION structure

    // Wait until child process exits.
    WaitForSingleObject( pi.hProcess, INFINITE );

    // Close process and thread handles. 
    CloseHandle( pi.hProcess );
    CloseHandle( pi.hThread );
}