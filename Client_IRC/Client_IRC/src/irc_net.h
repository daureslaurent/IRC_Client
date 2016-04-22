#pragma once
#include "reseau_cli.h"

#include <string>
#include <thread>
#include <chrono>

class irc_net : public reseau
{
public:
	irc_net();
	~irc_net();
	bool	connect(std::string nickname, std::string hostname, std::string username, std::string servname, std::string realname);

};

