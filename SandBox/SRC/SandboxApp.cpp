#include <Apollo.h>


class Sandbox : public Apollo::Application
{
public:
	Sandbox()
	{

	}
	~Sandbox()
	{

	}

};
Apollo::Application* Apollo::CreateApplication()
{
	return new Sandbox();
}