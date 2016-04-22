#pragma once
#include <iostream>
#include <string>
#include <vector>

class Server
{
public:
	std::string	_addr;
	int			_port;
};

class Mefile
{
public:
	std::string	_nickname;
	std::string	_username;
	std::string	_realname;
};

class Me
{
private:
	/* BDD */
	std::vector<Server> _lserv;
	std::vector<Server> _lme;
	void				save();
	void				load();
	/* Net arg */
	std::string _addr;
	int			_port;
	void	askNet();
	void	newNet();

	/* Me arg */
	std::string	_nickname;
	std::string	_username;
	std::string	_hostname;
	std::string	_servname;
	std::string	_realname;
	void	askMe();

public:
	Me();
	~Me();
	void	run();
	std::string	getAddr();
	int			getPort();
};

