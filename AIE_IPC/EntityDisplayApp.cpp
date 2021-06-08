#include "EntityDisplayApp.h"
#include "raylib.h"
#include <conio.h>

EntityDisplayApp::EntityDisplayApp(int screenWidth, int screenHeight) :
	Application(screenWidth, screenHeight, "Display App")
{
	m_fileHandle = OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE, m_memory);
	if (m_fileHandle == nullptr)
	{
		std::cout << "Could not create file mapping object: " << GetLastError() << std::endl;
		return;
	}

	m_data = (Entity*)MapViewOfFile(m_fileHandle, FILE_MAP_ALL_ACCESS, 0, 0, sizeof(Entity)* 10);
	if (m_data == nullptr)
	{
		std::cout << "Could not map view of file: " << GetLastError() << std::endl;
		CloseHandle(m_fileHandle);
		return;
	}
}

EntityDisplayApp::~EntityDisplayApp()
{
	UnmapViewOfFile(m_data);

	CloseHandle(m_fileHandle);
}

void EntityDisplayApp::Startup()
{
	
}

void EntityDisplayApp::Shutdown()
{

}

void EntityDisplayApp::Update(float deltaTime)
{
	m_entities.clear();

	for (int i = 0; i < 10; i++)
	{
		m_entities.push_back(m_data[i]);
	}
}

void EntityDisplayApp::Draw()
{
	BeginDrawing();

	ClearBackground(RAYWHITE);

	// draw entities
	for (auto& entity : m_entities) {

		DrawRectanglePro(
			Rectangle{ entity.x, entity.y, entity.size, entity.size }, // rectangle
			Vector2{ entity.size / 2, entity.size / 2 }, // origin
			entity.rotation,
			Color{ entity.r, entity.g, entity.b, 255 });
	}

	// output some text, uses the last used colour
	DrawText("Press ESC to quit", 630, 15, 12, LIGHTGRAY);

	EndDrawing();
}