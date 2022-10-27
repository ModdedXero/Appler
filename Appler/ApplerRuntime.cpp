#include <ApplerCore.h>

#include "ApplerLayer.h"

using namespace Appler;
using namespace Appler::Core;

class ApplerRuntime : public Application
{
public:
	ApplerRuntime()
	{
		PushLayer(new ApplerLayer());
	}
};

int main()
{
	Scope<ApplerRuntime> runtime = CreateScope<ApplerRuntime>();
	runtime->Run();

	return 0;
}