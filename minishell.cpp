#include <iostream>
#include <string>
#include <windows.h>

void runCommand(const std::string& input) {
    // Convert command to LPSTR
    std::string command = "cmd /C " + input;  // /C tells cmd.exe to run a command and exit
    LPSTR cmd = const_cast<char*>(command.c_str());

    STARTUPINFOA si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    // Create new process
    if (!CreateProcessA(
        nullptr,     // Application name (null means use command line)
        cmd,         // Command line
        nullptr,     // Process handle not inheritable
        nullptr,     // Thread handle not inheritable
        FALSE,       // Set handle inheritance to FALSE
        0,           // No creation flags
        nullptr,     // Use parent's environment block
        nullptr,     // Use parent's starting directory 
        &si,         // Pointer to STARTUPINFO structure
        &pi)         // Pointer to PROCESS_INFORMATION structure
    ) {
        std::cerr << "CreateProcess failed: " << GetLastError() << "\n";
        return;
    }

    // Wait until child process exits
    WaitForSingleObject(pi.hProcess, INFINITE);

    // Close process and thread handles
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
