#pragma once

#ifdef HZ_PLATFORM_WINDOWS

	// This must be defined in the CLIENT
	extern Hazel::Application* Hazel::CreateApplication();

	int main(int argc, char** argv)
	{

		auto app = Hazel::CreateApplication();
		app->Run();
		delete app;

	}

#endif