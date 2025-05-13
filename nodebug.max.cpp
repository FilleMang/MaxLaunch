#include <iostream>
#include <windows.h>
#include <string>
#include <shlwapi.h>

#pragma comment(lib, "shlwapi.lib")

int main(int argc, char* argv[]) {
    // Get the name of the current exe file
    char exePath[MAX_PATH];
    GetModuleFileNameA(NULL, exePath, MAX_PATH);
    std::string exePathStr(exePath); // Convert char array to std::string

    // Replace ".max.exe" with ".exe" in the executable path
    size_t maxPos = exePathStr.find(".max.exe");
    if (maxPos != std::string::npos) {
        exePathStr.replace(maxPos, 8, ".exe");
    } else {
        std::cerr << "Unknown exe name: " << exePathStr << std::endl;
        return 1;
    }

    // Check if the target exe file exists
    if (!PathFileExistsA(exePathStr.c_str())) {
        std::cerr << "Cannot find " << exePathStr << " in the same directory." << std::endl;
        return 1;
    }

    // Create the argument string for the target exe file
    std::string arguments;
    for (int i = 1; i < argc; ++i) {
        arguments += argv[i];
        if (i < argc - 1) {
            arguments += " ";
        }
    }

    // Start the target exe file in a maximized window with the arguments
    STARTUPINFO si = { sizeof(si) };
    PROCESS_INFORMATION pi;

    si.dwFlags = STARTF_USESHOWWINDOW;
    si.wShowWindow = SW_MAXIMIZE;

    if (!CreateProcessA(
        exePathStr.c_str(),
        const_cast<char*>(arguments.c_str()),
        NULL,
        NULL,
        FALSE,
        0,
        NULL,
        NULL,
        &si,
        &pi)) {
        std::cerr << "Could not start " << exePathStr << std::endl;
        return 1;
    }

    // Wait for the process to finish
    WaitForSingleObject(pi.hProcess, INFINITE);

    // Close the handles
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return 0;
}
