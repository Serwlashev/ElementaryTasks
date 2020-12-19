#include "ParserApplication.h"

int main(int argc, char* argv[]) {
	ISXApplication::ParserApplication app;
	app.Parse(argc, argv);

	return 0;
}