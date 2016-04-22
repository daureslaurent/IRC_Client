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
		int			selec;
		std::cin >> sSelec;
		selec = std::atoi(sSelec.c_str());
		if (selec >= 0 && selec <= _lserv.size())
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

void Me::askMe()
{
	if (_lserv.size() > 0)
	{
		std::cout << "Config user list:" << std::endl;

		for (size_t i = 0; i < _lme.size(); i++)
			std::cout << "[" << i << "] " << _lme[i]._addr << std::endl;
		std::cout << "Choose the target server [nb]: ";
		std::string	sSelec;
		int			selec;
		std::cin >> sSelec;
		selec = std::atoi(sSelec.c_str());
		if (selec >= 0 && selec <= _lme.size())
		{
			_addr = _lme[selec]._addr;
			_port = _lme[selec]._port;
		}
		else
			newNet();
	}
	else
		newNet();
}

Me::Me()
{
}


Me::~Me()
{
}

void Me::run()
{
	std::cout << "Me obj:" << std::endl;
	askNet();
	system("cls");
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
