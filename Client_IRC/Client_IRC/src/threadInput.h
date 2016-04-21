#pragma once
#include <thread>
#include <mutex>
#include <iostream>
#include <string>
#include "irc_net.h"

class threadInput
{
private:
	std::thread _thread;
	bool		_exit;
	irc_net		_net;
	std::mutex	_mut;

	bool	checkCmd(std::string);
public:
	threadInput();
	~threadInput();

	void	start(irc_net);
	void	stop();
	void	Dojob();
	bool	getEtat();
};

