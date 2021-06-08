#pragma once
//#define WIN32_LEAN_AND_MEAN
//#include <Windows.h>

#include "raylib.h"
#include "FixWindows.h"
#include <winnt.h>

#include "Entity.h"

#include <iostream>

class Application
{
public:
	bool isOpen = false;

	Application(int screenWidth, int screenHeight, const char *windowTitle);
	virtual ~Application();

	void Run();

	virtual void Startup() = 0;
	virtual void Shutdown() = 0;

	virtual void Update(float deltaTime) = 0;
	virtual void Draw() = 0;

protected:


	int m_screenWidth;
	int m_screenHeight;
	const char* m_windowTitle;

	enum { ENTITY_COUNT = 10 };
	HANDLE m_fileHandle;
	Entity* m_data;
	Entity m_entities[ENTITY_COUNT];

	const wchar_t* m_memory = L"MySharedMemory";
private:
};
