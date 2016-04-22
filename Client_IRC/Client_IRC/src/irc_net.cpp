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
	std::this_thread::sleep_for(std::chrono::seconds(1));
	Recv();

	std::string nickReq = "NICK " + nickname + "\r\n";
	std::string userkReq = "USER " + username + " " +hostname + " " + servname + " :" + realname + "\r\n";
	
	Send(nickReq);
	Send(userkReq);
	return true;
}
