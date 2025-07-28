#include <iostream>
#include <string>
#include <windows.h>

void runCommand(const std::string& input) {
    
    std::string command = "cmd /C " + input;  
    LPSTR cmd = const_cast<char*>(command.c_str());

    STARTUPINFOA si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    // Create new process
    if (!CreateProcessA(
        nullptr,     
        cmd,         
        nullptr,   
        nullptr,    
        FALSE,       
        0,           
        nullptr,     
        nullptr,     
        &si,         
        &pi)         
    ) {
        std::cerr << "CreateProcess failed: " << GetLastError() << "\n";
        return;
    }

    
    WaitForSingleObject(pi.hProcess, INFINITE);

    
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
}

int main() {
    std::string input;

    std::cout << "MiniShell for Windows (type 'exit' to quit)\n";

    while (true) {
        std::cout << "myshell> ";
        std::getline(std::cin, input);

        if (input == "exit")
            break;

        if (!input.empty())
            runCommand(input);
    }

    return 0;
}
