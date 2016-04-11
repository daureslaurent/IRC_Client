#pragma once
#include "irc_net.h"
#include <string>
class clientIrc
{
private:
	irc_net	_net;

	bool	Init();
	bool	checkCmd(std::string inData);

public:
	clientIrc();
	~clientIrc();

	bool Run();
};

