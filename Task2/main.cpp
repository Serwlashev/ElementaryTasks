#include <iostream>

#include "Application.h"

int main(int argc, char* argv[])
{
	ISXApp::Application* app = new ISXApp::Application();;
	if (app != nullptr) {
		app->Start(argc, argv);

		delete app;
	}

	system("pause");
	return 0;
}