#include <iostream>
#include <fstream>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;

void createByInput(const string& cmd, bool flag) {
	//parameter setup and inittialization of STARTUPINFO&PROCESS_INFORMATION
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	ZeroMemory(&si, sizeof(si));
	si.cb=sizeof(STARTUPINFO);
	si.dwFlags=STARTF_USESHOWWINDOW;
	si.wShowWindow=SW_SHOW;
	ZeroMemory(&pi, sizeof(pi));
	
	if (flag) {
		//open file by application
		char line[256];
		for (int i = 0, len = cmd.length(); i < len; ++i) {
			line[i] = cmd[i];
		}
		// Start the child process. 
		if (!CreateProcess(NULL,   
			line,        
			NULL,           // Process handle not inheritable
			NULL,           // Thread handle not inheritable
			FALSE,          // Set handle inheritance to FALSE
			0,              // No creation flags
			NULL,           // Use parent's environment block
			NULL,           // Use parent's starting directory 
			&si,            // Pointer to STARTUPINFO structure
			&pi)           // Pointer to PROCESS_INFORMATION structure
			) {
			printf("CreateProcess failed (%d).\n", GetLastError());
			return;
		}
	} else {
		// Start the child process. 
		if (!CreateProcess(cmd.c_str(),   
			NULL,        
			NULL,           // Process handle not inheritable
			NULL,           // Thread handle not inheritable
			FALSE,          // Set handle inheritance to FALSE
			0,              // No creation flags
			NULL,           // Use parent's environment block
			NULL,           // Use parent's starting directory 
			&si,            // Pointer to STARTUPINFO structure
			&pi)           // Pointer to PROCESS_INFORMATION structure
			)
		{
			printf("CreateProcess failed (%d).\n", GetLastError());
			return;
		}
	}
	// Wait until child process exits.
	// Close process and thread handles. 
	WaitForSingleObject(pi.hProcess, INFINITE);
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
}

int main() {
	string cmd;
	while (true) {
		// get intput commands
		printf("$ ");
		getline(cin, cmd);
		
		if (cmd == "exit") break;
		
		size_t exeCheck = cmd.find("exe");
		size_t txtCheck = cmd.find("txt");
		
		if (exeCheck != string::npos && txtCheck != string::npos) {  //open file by application
			createByInput(cmd, true);
		} else if (exeCheck != string::npos && txtCheck == string::npos) {  //run the program directly
			createByInput(cmd, false);
		} else if (exeCheck == string::npos && txtCheck != string::npos) {  //open file and get commands
			ifstream infile;
			infile.open(cmd.c_str());
			if (!infile) {
				cout << "open file failed\n";
			} else {
				string buff;
				while (getline(infile, buff))
				{
					createByInput(buff, false);
				}
				infile.close();
			}
		} else {														//pop-up box about error
			MessageBox (NULL, TEXT ("the cmd does not exist\n"), TEXT ("ÌבÊ¾"), 0) ; 
		}
	}
	return 0;
}
