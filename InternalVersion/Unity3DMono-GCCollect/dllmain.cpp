// dllmain.cpp : Defines the entry point for the DLL application.
#include <Windows.h>
#include "Feat/Includes.h"
int dx11wrap = 8;
void CreateConsole() {
    AllocConsole();
    SetConsoleTitleA("MonoUnity3D_GCCollect by RiritoXXL");
    FILE* fp;
    freopen_s(&fp, "CONOUT$", "w", stdout);
    cout << "Welcome to the My First Internal DLL Program for Collecting Memory Usage..." << endl;
}
DWORD WINAPI MainThread() {
    bool init_hook = false;
	CreateConsole();
	do
	{
		if (kiero::init(kiero::RenderType::D3D11) == kiero::Status::Success)
		{
			kiero::bind(dx11wrap, (void**)&oPresent, ImG::Pres);
			init_hook = true;
			cout << "Kiero Has Been Successfully Initializated" << endl;
		}
		else {
			cout << "KIERO IS DEAD... LONG LIVE THE NEW KIERO!!!" << endl;
			Sleep(4500);
			exit(122);
		}
		if (GetAsyncKeyState(VK_F5))
		{
			kiero::shutdown();
			FreeLibraryAndExitThread(NULL, 950);
		}
	} while (!init_hook);
	return TRUE;
}
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
		CreateThread(0, 0, (LPTHREAD_START_ROUTINE)MainThread, 0, 0, 0);
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

