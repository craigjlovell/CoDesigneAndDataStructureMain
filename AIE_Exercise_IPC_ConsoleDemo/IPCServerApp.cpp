#include "IPCServerApp.h"
#include "Memory.h"
#include <windows.h>
#include <conio.h>
#include <iostream>
#include <time.h>


IPCServerApp::IPCServerApp()
{

    m_fileHandle = CreateFileMapping(
        INVALID_HANDLE_VALUE, // a handle to an existing virtual file, or invalid
        nullptr, // optional security attributes
        PAGE_READWRITE, // read/write access control
        0,
        sizeof(MyData), // size of the memory block, 
        m_memory);

    if (m_fileHandle == nullptr)
    {
        std::cout << "Could not create file mapping object: " <<
            GetLastError() << std::endl;

        return;
    }

    m_data = (MyData*)MapViewOfFile(m_fileHandle,
        FILE_MAP_ALL_ACCESS,
        0,
        0,
        sizeof(MyData));

    if (m_data == nullptr)
    {
        std::cout << "Could not map view of file: " <<
            GetLastError() << std::endl;

        CloseHandle(m_fileHandle);
        return;
    }
}

IPCServerApp::~IPCServerApp()
{
    UnmapViewOfFile(m_data);

    CloseHandle(m_fileHandle);
}

void IPCServerApp::PushRun()
{
    srand(time(NULL));    

    MyData myData = { rand() % 100, rand() % 10000 / 100.0f, rand() % 32 + 'A', rand() % 2 , rand() % 10000 / 100.0f };

    if (_getch() == 27)
    {
        close = true;
    }
    else
    {
        *m_data = myData;
    }
    
    return;
}

void IPCServerApp::Run()
{
    while (!close)
    {
        PushRun();
    }
}