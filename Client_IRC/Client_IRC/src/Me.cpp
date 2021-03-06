#include "Me.h"



void Me::askNet()
{
	if (_lserv.size() > 0)
	{
		std::cout << "Serveur list:" << std::endl;

		for (size_t i = 0; i < _lserv.size(); i++)
			std::cout << "[" << i << "] " << _lserv[i]._addr << std::endl;
		std::cout << "Choose the target server [nb]: ";
		std::string	sSelec;
		size_t			selec;
		std::cin >> sSelec;
		selec = std::atoi(sSelec.c_str());
		if (selec <= _lserv.size())
		{
			_addr = _lserv[selec]._addr;
			_port = _lserv[selec]._port;
		}
		else
			newNet();
	}
	else
		newNet();
}

void Me::newNet()
{
	std::string sPort, sAddr, save;
	std::cout << "Enter adresse :";
	std::cin >> _addr;
	std::cout << "Enter port :";
	std::cin >> sPort;
	_port = std::atoi(sPort.c_str());
	if (SAVE_ENGINE)
	{
		std::cout << "Do you want save ? [Y/N] :";
		std::cin >> save;
		if (save[0] == 'y' || save[0] == 'Y')
		{
			Server serv;
			serv._addr = sAddr;
			serv._port = _port;
			_lserv.push_back(serv);
			std::cout << "Save !" << std::endl;
		}
	}
}

void Me::askMe()
{
	if (_lme.size() > 0)
	{
		std::cout << "Config user list:" << std::endl;
		for (size_t i = 0; i < _lme.size(); i++)
		{
			std::cout << "[" << i << "] " << _lme[i]._nickname;
			std::cout << " - " << _lme[i]._username;
			std::cout << " - " << _lme[i]._realname << std::endl;
		}
		std::cout << "Choose your config[nb]: ";
		std::string	sSelec;
		size_t			selec;
		std::cin >> sSelec;
		selec = std::atoi(sSelec.c_str());
		if (selec <= _lme.size())
		{
			_nickname = _lme[selec]._nickname;
			_username = _lme[selec]._username;
			_realname = _lme[selec]._realname;
		}
		else
			newMe();
	}
	else
		newMe();
	std::cout << "Enter your password [If none enter 'n' or 'N']" << std::endl;
	std::cin >> _password;
}

void Me::newMe()
{
	std::string nickname, username, realname, save;
	std::cout << "Enter your nickname :";
	std::cin >> nickname;
	std::cout << "Enter your username :";
	std::cin >> username;
	std::cout << "Enter your realname :";
	std::cin >> realname;
	if (SAVE_ENGINE)
	{
		std::cout << "Do you want save ? [Y/N] :";
		std::cin >> save;
		if (save[0] == 'y' || save[0] == 'Y')
		{
			Mefile me;
			me._nickname = nickname;
			me._username = username;
			me._realname = realname;
			_lme.push_back(me);
			std::cout << "Save !" << std::endl;
		}
	}
	_nickname = nickname;
	_username = username;
	_realname = realname;
}

Me::Me()
{
}


Me::~Me()
{
}

void Me::run()
{
	askNet();
	askMe();
#ifdef _WIN32
	system("cls");
#else
	int ret = system("clear");
	ret++; //Suppres Warning
#endif
	//Clean screen
}

std::string Me::getAddr()
{
	return _addr;
}

int Me::getPort()
{
	return _port;
}

std::string Me::getNick()
{
	return _nickname;
}

std::string Me::getHostName()
{
	return "bothost";
}

std::string Me::getUserName()
{
	return _username;
}

std::string Me::getServName()
{
	return "ircname";
}

std::string Me::getRealName()
{
	return _realname;
}

std::string Me::getPassword()
{
	return _password;
}
