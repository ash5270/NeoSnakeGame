#include <iostream>
#include "include/system/Application.hpp"
int main() 
{
	neo::system::Application app;
	app.Init();
	app.Start();
	app.Update();
	app.Stop();
	return 0;
}
