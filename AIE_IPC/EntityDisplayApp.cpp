#include "EntityDisplayApp.h"
#include "raylib.h"
#include <conio.h>

EntityDisplayApp::EntityDisplayApp(int screenWidth, int screenHeight) :
	Application(screenWidth, screenHeight, "Display App")
{
	
}

EntityDisplayApp::~EntityDisplayApp()
{
	
}

void EntityDisplayApp::Startup()
{

}

void EntityDisplayApp::Shutdown()
{

}

void EntityDisplayApp::Update(float deltaTime)
{
	m_fileHandle = OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE, m_memory);

	if (m_fileHandle != nullptr)
	{
		isOpen = true;
	}

	m_data = (Entity*)MapViewOfFile(m_fileHandle, FILE_MAP_ALL_ACCESS, 0, 0, sizeof(Entity) * ENTITY_COUNT);

	if (m_data == nullptr)
	{
		isOpen = false;
		CloseHandle(m_fileHandle);
		return;
	}

	m_entities.clear();

	for (int i = 0; i < ENTITY_COUNT; i++)
	{
		m_entities.push_back(m_data[i]);
	}

	UnmapViewOfFile(m_data);

	CloseHandle(m_fileHandle);
}

void EntityDisplayApp::Draw()
{
	BeginDrawing();

	ClearBackground(RAYWHITE);

	if (isOpen)
	{
		// draw entities
		for (auto& entity : m_entities)
		{
			DrawRectanglePro(
				Rectangle{ entity.x, entity.y, entity.size, entity.size }, // rectangle
				Vector2{ entity.size / 2, entity.size / 2 }, // origin
				entity.rotation,
				Color{ entity.r, entity.g, entity.b, 255 });
		}
	}
	else
	{
		DrawText("Entity Editor App not open!", 100, 100, 32, RED);
	}

	// output some text, uses the last used colour
	DrawText("Press ESC to quit", 630, 15, 12, LIGHTGRAY);

	EndDrawing();
}