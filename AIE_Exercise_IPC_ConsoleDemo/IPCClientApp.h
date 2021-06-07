#pragma once

#include "Application.h"
#include "Memory.h"
#include <windows.h>

class IPCClientApp : public Application
{
public:

	IPCClientApp();
	virtual ~IPCClientApp();

	void PushRun();
	virtual void Run();

protected:

private:
};