#include <iostream>
#include <LuaPlus/LuaPlus.h>
#include "Manipulator.h"

void Exit(void);

int main(void)
{
	Manipulator manipulator = Manipulator(60, 30);
	LPCD::LuaStateOwner state;
	std::string str;

	state->GetGlobals().RegisterDirect("go_stright", manipulator, &Manipulator::go_stright);
	state->GetGlobals().RegisterDirect("exit", Exit);

	while(1)
	{
		std::cout << "> ";
		getline(std::cin, str);
		state->DoString(str.c_str());
	}

	return 0;
}

void Exit(void) { exit(0); }
