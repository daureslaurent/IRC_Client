#include "irc_net.h"



irc_net::irc_net()
{
}


irc_net::~irc_net()
{
}

bool irc_net::connect(std::string nickname, std::string hostname, std::string username,
	std::string servname, std::string realname, std::string password)
{
	std::this_thread::sleep_for(std::chrono::seconds(1));
	Recv();

	std::cout << nickname << ":" << hostname << ":" << username << ":" << servname << ":" << realname << ":" << password << std::endl;
	std::string passReq = "PASS " + password + "\r\n";
	std::string nickReq = "NICK " + nickname + "\r\n";
	std::string userkReq = "USER " + username + " " + hostname + " " + servname + " :" + realname + "\r\n";
	if (password.size() < 1)
		Send(passReq);
	Send(nickReq);
	Send(userkReq);
	return true;
}
