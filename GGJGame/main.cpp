#include "Application.h"
#include "Game.h"

int main()
{
	Application app(new Game());

	while (app.isRunning())
		app.update();

	return 0;
}