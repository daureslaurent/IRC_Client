#pragma once
#include "irc_net.h"
#include "MessageManager.h"
#include <string>
#include <thread>
#include "threadInput.h"
#include "Me.h"
#define	DEBUG	false

class clientIrc
{
private:
	irc_net		_net;
	Me			_me;
	int			_port;
	std::string	_addr;
	threadInput thinput;
	MessageManager _msgman;

	bool	Init();
	bool	checkCmd(Message inData);

public:
	clientIrc();
	~clientIrc();

	bool Run();
};

