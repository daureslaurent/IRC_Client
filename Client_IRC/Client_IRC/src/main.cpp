#include <iostream>
#include <new>
#include "clientIrc.h"

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;

	clientIrc irc;
	irc.Run();
	return 0;
}