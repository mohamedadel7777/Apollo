#pragma once

#ifdef AP_PLATFORM_WINDOWS
extern Apollo::Application* Apollo::CreateApplication();
int main(int argc, char** argv)
{
	auto app = Apollo::CreateApplication();
	app->Run();
	delete app;
}
#endif
