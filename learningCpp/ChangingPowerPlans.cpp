#include <iostream>
<<<<<<< HEAD
#include <windows.h>
#include <tlhelp32.h>
=======
>>>>>>> cdab033 (updated learning)



using namespace std;


class PowerPlan {
public:
	const char* balanced(const char* plan) {
		plan = "powercfg /s 381b4222-f694-41f0-9685-ff5bb260df2e";
		return plan;
	}
};


// const char* balanced = "powercfg /s 381b4222-f694-41f0-9685-ff5bb260df2e";
// const char* ultimatePerf = "powercfg /s a30b9cd3-2e5a-4ed6-b690-e7835b748e87";
// const char* highPerf= "powercfg /s 8c5e7fda-e8bf-4a96-9a85-a6e23a8c635c";
// const char* powerSave = "powercfg /s a1841308-3541-4fab-bc81-f71556f20b4a";


<<<<<<< HEAD
BOOL isRunning(BOOL bShow/*=TRUE*/)
{
	BOOL bRunning = FALSE;
	CString strAppName;
	strAppName.LoadString(AFX_IDS_APP_TITLE);
	hwnd = FindWindow(NULL, pName);
	if (hwnd != 0) {
		return true;
	} else {
		return false;
	}
}
=======
>>>>>>> cdab033 (updated learning)

int main() 
{
	
	const char* power[] = {"powercfg /s 381b4222-f694-41f0-9685-ff5bb260df2e", "powercfg /s a30b9cd3-2e5a-4ed6-b690-e7835b748e87", "powercfg /s 8c5e7fda-e8bf-4a96-9a85-a6e23a8c635c", "powercfg /s a1841308-3541-4fab-bc81-f71556f20b4a"};

	const char* balanced = power[0];
	const char* highperf = power[2];
	const char* powersave = power[3];
	const char* ultimateperf = power[1];


<<<<<<< HEAD
	int returnCode{system("dir")};
=======
	int returnCode{system("ls")};
>>>>>>> cdab033 (updated learning)


	// Checks if command executed successfully.
	if (returnCode == 0)
	{
		cout << "Command successfully executed \n";
	}
	else
	{
		cout << "Command execution failed \n" << returnCode;
	}

	// Software To Detectr
	const char* osu = "0x507f0";
	const char* Cs2 = "0x2068c";
	const char* theFinals = "0x3106b2";


	//HWND winFind = FindWindow(NULL, "Notepad.exe");

<<<<<<< HEAD

	std::cout << "Finding the window here: " << isRunning("NotePad.exe");


	std::cout << "\n\n";

=======
	std::cout << "Finding the window here: ";
	std::cout << "\n\n";
>>>>>>> cdab033 (updated learning)
	std::cout << "Hi how are ya";


	// std::cout << power[0];
};