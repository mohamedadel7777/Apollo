#pragma once
#include"Log.h"

#ifdef AP_PLATFORM_WINDOWS
extern Apollo::Application* Apollo::CreateApplication();
int main(int argc, char** argv)
{
	Apollo::Log::Init();
	auto app = Apollo::CreateApplication();
	app->Run();
	delete app;
}
#endif
