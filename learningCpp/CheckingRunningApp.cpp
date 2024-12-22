#include <iostream>
#include <handleapi.h>
#include <minwindef.h>
#include <processthreadsapi.h>
#include <tlhelp32.h>

BOOL AppIsAllreadyRunning(BOOL bShow=TRUE);
BOOL CALLBACK ShowAppEnum( HWND hwnd, LPARAM lParam );



BOOL AppIsAllreadyRunning(BOOL bShow)
{
	BOOL bRunning = FALSE;
	CString strAppName;
	strAppName.Loadstring(AFX_IDS_APP_TITLE);
	strAppName += _T(".exe");
	DWORD dwOwnPID = GetProcessId(GetCurrentProcess());
	HANDLE hSnapShot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,0);
	PROCESSENTRY32* processInfo = new PROCESSENTRY32;
	processInfo->dwSize = sizeof(PROCESSENTRY32);
	int index = 0;
	while (Process32Next(hSnapShot,processInfo) != FALSE)
	{
		if (!strcmp(processInfo->szExeFile, strAppName))
			if (processInfo->th32ProcessID != dwOwnPID)
			{
				if (bShow)
					EnumWindows(ShowAppEnum, processInfo->th32ProcessID);
				bRunning = TRUE;
				break;
			}
	}
}
CloseHandle(hSnapShot);
delete processInfo;
return bRunning;