#include "clientIrc.h"



bool clientIrc::Init()
{
	std::cout << "Client IRC(WIN/UNIX)" << std::endl;
	// Get host:ip
	if (!_net.Init("irc.ircube.org", 6667))
		return false;
	return true;
}

bool clientIrc::checkCmd(std::string inData)
{
	std::cout << "RECV[" << inData << "]" << std::endl;
	if (!inData.compare(0, 5, "PING "))
	{
		inData.erase(inData.size() - 2, 2);
		inData.erase(0, 6);
		std::string pongReq = "PONG " + inData + "\r\n";
		_net.Send(pongReq);
	}
	return false;
}

clientIrc::clientIrc()
{
}


clientIrc::~clientIrc()
{
}

bool clientIrc::Run()
{
	if (!Init())
		return false;

	_net.connect("nickname", "hostname", "servname", "Real Name");
	while (true)
	{
		checkCmd(_net.Recv());
	}
	std::cout << "NEW REQ:" << _net.Recv() << std::endl;
}
