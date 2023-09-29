#include <Myth.h>


class SandBox : public Myth::Application
{
public:
	SandBox()
	{

	};

	~SandBox()
	{

	};
};

Myth::Application* Myth::CreateApplication()
{
	return new SandBox();
}

