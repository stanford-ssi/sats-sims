#include <iostream>
#include "Engine.h"


using namespace EE;

int main()
{
	// Create engine and load a blank space
	Engine* eng = new Engine();
	Space* space = new Space();
	eng->loadSpace(space);

	eng->addEntity("Test1");
	eng->addComponent("Test1", "TestComponent");
	eng->addSystem("TestSystem");
	eng->addSysDependency("TestSystem", "TestComponent");

	eng->debugEntity("Test1");
	eng->debugSpace();
	eng->debugSystem("TestSystem");

	eng->addEntity("Test2");
	eng->addComponent("Test2", "TestComponent");

	eng->debugEntity("Test1");
	eng->debugEntity("Test2");
	eng->debugSpace();
	eng->debugSystem("TestSystem");

	eng->removeEntity("Test1");
	eng->removeComponent("Test2", "TestComponent");
	
	eng->debugSpace();
	eng->debugSystem("TestSystem");

	return 0;
}