#pragma once

#include "Application.h"
#include <windows.h>
#include "Memory.h"

class IPCServerApp : public Application
{
public:

	IPCServerApp();
	virtual ~IPCServerApp();

	void PushRun();
	virtual void Run();

protected:

private:
};