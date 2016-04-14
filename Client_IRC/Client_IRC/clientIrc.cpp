#include "clientIrc.h"
#include "threadInput.h"
#include <thread>


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
	if (!inData.compare(0, 5, "PING "))
	{
		inData.erase(inData.size() - 2, 2);
		inData.erase(0, 6);
		std::string pongReq = "PONG " + inData + "\r\n";
		_net.Send(pongReq);
	}
	else
	{
		//std::cout << "\r" << output << padding << "\n" << currentinput;
		std::cout << "-> " << inData << std::endl;
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

	if (_net.connect("nickname123", "hostnamelo", "lolodudidi", "servname", "Real Name"))
	{
		threadInput thinput;
		thinput.start(_net);
		while (true)
		{
			checkCmd(_net.Recv());
		}
	}
}
