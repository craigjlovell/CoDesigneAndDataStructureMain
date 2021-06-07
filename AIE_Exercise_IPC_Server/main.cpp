#include <iostream>
#include <windows.h>
#include <conio.h>

struct MyData
{
    int i;
    float f;
    char c;
    bool b;
    double d;
};

int main()
{
    MyData myData = { 99, 7.56f, 'A', true, 69.42 };

    HANDLE fileHandle = CreateFileMapping(
        INVALID_HANDLE_VALUE, // a handle to an existing virtual file, or invalid
        nullptr, // optional security attributes
        PAGE_READWRITE, // read/write access control
        0,
        sizeof(MyData), // size of the memory block, 
        L"MySharedMemory");

    if (fileHandle == nullptr)
    {
        std::cout << "Could not create file mapping object: " <<
            GetLastError() << std::endl;

        return 1;
    }

    MyData* data = (MyData*)MapViewOfFile(fileHandle,
        FILE_MAP_ALL_ACCESS,
        0,
        0,
        sizeof(MyData));

    if (data == nullptr) 
    {
        std::cout << "Could not map view of file: " <<
            GetLastError() << std::endl;

        CloseHandle(fileHandle);
        return 1;
    }

    *data = myData;

    _getch();

    UnmapViewOfFile(data);

    CloseHandle(fileHandle);

    return 0;
}