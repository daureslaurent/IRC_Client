#pragma once
#include "irc_net.h"
#include "MessageManager.h"
#include <string>
#include <thread>
#include "threadInput.h"


class clientIrc
{
private:
	irc_net		_net;
	int			_port;
	std::string	_addr;
	threadInput thinput;
	MessageManager _msgman;

	bool	Init();
	bool	checkCmd(Message inData);
	void	Asknet();

public:
	clientIrc();
	~clientIrc();

	bool Run();
};

