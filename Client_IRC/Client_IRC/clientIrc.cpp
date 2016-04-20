#include "clientIrc.h"
#include "threadInput.h"
#include <thread>

#include "util.h"

bool clientIrc::Init()
{
	Asknet();
	if (!_net.Init(_addr, _port))
		return false;
	return true;
}

void	clientIrc::Asknet()
{
	std::string port;
	std::cout << "Enter adresse :";
	std::cin >> _addr;
	std::cout << "Enter port :";
	std::cin >> port;
	_port = std::atoi(port.c_str());
}

bool clientIrc::checkCmd(std::string inData)
{
	ns::Fonction1();
	if (!inData.compare(0, 5, "PING "))
	{
		inData.erase(inData.size() - 2, 2);
		inData.erase(0, 6);
		std::string pongReq = "PONG " + inData + "\r\n";
		_net.Send(pongReq);
	}
	else
	{
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
