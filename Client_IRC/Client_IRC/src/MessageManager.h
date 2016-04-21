#pragma once
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include "util.h"

class Message
{
public:
	std::string data;
	int			headCode;
	/* if PRIVMSG*/
	std::string	from;
	std::string	to;
};

class MessageManager
{
private:
	std::vector<Message>	_list;
public:
	MessageManager();
	~MessageManager();
	void		parse(std::string data);
	bool		getLoop();
	Message		exec();
};

