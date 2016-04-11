#include <iostream>
#include "reseau_cli.h"
#include "irc_net.h"

int	main(int ac, char **av)
{
	irc_net	net;
	std::cout << "Client IRC(WIN/UNIX)" << std::endl;
	// Get host:ip
	net.Init("irc.ircube.org", 6667);
	net.connect("nickname", "hostname", "servname", "Real Name");

	system("Pause");

	return 0;
}