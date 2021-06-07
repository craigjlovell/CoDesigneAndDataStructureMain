#pragma once
#include "Memory.h"
#include <windows.h>

class Application
{
public:
    
    Application();
    virtual ~Application();

    virtual void Run() = 0;

protected:
    const wchar_t* m_memory = L"MySharedMemory";

    bool close = false;

    HANDLE m_fileHandle;
    MyData* m_data;

private:
};