#include "clientIrc.h"


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

bool clientIrc::checkCmd(Message msg)
{
	std::string inData = msg.data;
	if (!inData.compare(0, 5, "PING "))
	{
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
		thinput.start(_net);
		while (true)
		{
			
			_msgman.parse(_net.Recv());
			while (_msgman.getLoop())
				checkCmd(_msgman.exec());
		}
	}
}
