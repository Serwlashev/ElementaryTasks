#include <iostream>

#include "Application.h";

int main()
{
	ISXApp::Application* app = new ISXApp::Application();;
	if (app != nullptr) {
		app->Start();

		delete app;
	}

	system("pause");
	return 0;
}