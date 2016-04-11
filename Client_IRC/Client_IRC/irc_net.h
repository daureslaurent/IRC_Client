#pragma once
#include "reseau_cli.h"

#include <string>

class irc_net : public reseau
{
public:
	irc_net();
	~irc_net();
	bool	connect(std::string nickname, std::string hostname, std::string servname, std::string realname);

};

