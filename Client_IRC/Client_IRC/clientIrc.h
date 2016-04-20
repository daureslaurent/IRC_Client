#pragma once
#include "irc_net.h"
#include <string>
class clientIrc
{
private:
	irc_net		_net;
	int			_port;
	std::string	_addr;

	bool	Init();
	bool	checkCmd(std::string inData);
	void	Asknet();

public:
	clientIrc();
	~clientIrc();

	bool Run();
};

