#include "irc_net.h"



irc_net::irc_net()
{
}


irc_net::~irc_net()
{
}

bool irc_net::connect(std::string nickname, std::string hostname, std::string username,
						std::string servname, std::string realname)
{
	std::cout << "Start connect[" << Recv() << "]" << std::endl;

	std::string nickReq = "NICK " + nickname + "\r\n";
	std::string userkReq = "USER " + username + " " +hostname + " " + servname + " :" + realname + "\r\n";
	
	Send(nickReq);
	Send(userkReq);
	
	std::cout << "Ret connect[" << Recv() << "]" << std::endl;

	return true;
}