#include <iostream>
#include <new>
#include "clientIrc.h"

int	main(int ac, char **av)
{
	clientIrc irc;
	irc.Run();

	system("PAUSE");
	return 0;
}