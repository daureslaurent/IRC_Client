#include "clientIrc.h"


bool clientIrc::Init()
{
	_me.run();
	if (!_net.Init(_me.getAddr(), _me.getPort()))
	{
		std::cout << "Connect to " << _me.getAddr() << std::endl;
		return false;
	}
	return true;
}

bool clientIrc::checkCmd(Message msg)
{
	if (!msg.data.compare(0, 5, "PING "))
	{
		msg.data.erase(0, 6);
		std::string pongReq = "PONG " + msg.data + "\r\n";
		_net.Send(pongReq);
	}
	else if (msg.data.find("JOIN") != std::string::npos)
	{
		std::string channel = msg.data.substr(msg.data.find_last_of(":") + 1);
		std::cout << "Channel " << channel << " join" << std::endl;
		thinput.setTarget(channel);
	}
	else if (msg.headCode == 372)
		std::cout << "-> " << msg.data.substr(msg.data.find(":-") + 2) << std::endl;
	else if ((msg.headCode == 322) && (msg.data.find('#') != std::string::npos))
		std::cout << "- " << msg.data.substr(msg.data.find("#")) << std::endl;
	else if (msg.headCode == 353)
		std::cout << "Liste des utilisateurs: " << msg.data.substr(msg.data.find_last_of(":")) << std::endl;
	else if (msg.headCode == 1001)
		std::cout << msg.from << "->" << msg.to << ":" << msg.data << std::endl;
	else if (msg.headCode == 433)
		std::cout << "Nickname in use :/" << std::endl;
	else if (DEBUG)
		std::cout << msg.headCode << "..>" << msg.data << std::endl;
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

	if (_net.connect(_me.getNick(), _me.getHostName(), _me.getUserName(), _me.getServName(), _me.getRealName(), _me.getPassword()))
	{
		thinput.start(_net);
		while (thinput.getEtat())
		{
			_msgman.parse(_net.Recv());
			while (_msgman.getLoop())
				checkCmd(_msgman.exec());
		}
	}
	thinput.stop();
	return true;
}
