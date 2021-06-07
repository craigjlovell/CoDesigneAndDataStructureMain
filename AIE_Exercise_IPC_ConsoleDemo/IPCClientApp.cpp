#include "IPCClientApp.h"
#include "Memory.h"
#include <windows.h>
#include <iostream>
#include <conio.h>

IPCClientApp::IPCClientApp()
{

    m_fileHandle = OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE, m_memory);
    if (m_fileHandle == nullptr)
    {
        std::cout << "Could not create file mapping object: " << GetLastError() << std::endl;
        return;
    }

    m_data = (MyData*)MapViewOfFile(m_fileHandle, FILE_MAP_ALL_ACCESS, 0, 0, sizeof(MyData));
    if (m_data == nullptr)
    {
        std::cout << "Could not map view of file: " << GetLastError() << std::endl;
        CloseHandle(m_fileHandle);
        return;
    }
}

IPCClientApp::~IPCClientApp()
{
    UnmapViewOfFile(m_data);

    CloseHandle(m_fileHandle);
}

void IPCClientApp::PushRun()
{
    system("CLS");

    std::cout << "MyData = { ";
    std::cout << m_data->i << ", ";
    std::cout << m_data->f << ", ";
    std::cout << m_data->c << ", ";
    std::cout << m_data->b << ", ";
    std::cout << m_data->d << ", ";
    std::cout << " };" << std::endl;

    Sleep(500);

    return;
}

void IPCClientApp::Run()
{
    while (!close)
    {
        PushRun();
    }

}