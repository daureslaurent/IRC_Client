#include "threadInput.h"



bool threadInput::checkCmd(std::string inData)
{
	if ((inData.size() >= 1) && (inData[0] != '/'))
	{
		std::string req = "PRIVMSG ";
		req += _target + " ";
		req += inData + "\r\n";
		_net.Send(req);
	}
	else if (!inData.compare("/quit"))
	{
		_net.Send("QUIT\r\n");
		_exit = false;
		std::cout << "EXIT CLIENT" << std::endl;
	}
	else if (inData[0] == '/')
	{
		inData.erase(inData.begin());
		size_t f0 = inData.find(" ");
		std::string cmd;
		std::string end = "";
		if (f0 != std::string::npos)
		{
			cmd = inData.substr(0, f0);
			end = inData.substr(f0);
		}
		else
			cmd = inData;
		for (size_t i = 0; i < cmd.size(); i++)
			cmd[i] = toupper(cmd[i]);
		_net.Send(cmd + end + "\r\n");
	}
	return true;
}

threadInput::threadInput()
{
}


threadInput::~threadInput()
{
}

void threadInput::start(irc_net net)
{
	_exit = true;
	_net = net;
	_thread = std::thread(std::bind(&threadInput::Dojob, this));
}

void threadInput::stop()
{
	_mut.lock();
	_exit = false;
	_mut.unlock();
	_thread.join();
}

void threadInput::Dojob()
{
	bool exit = true;

	while (exit)
	{
		char	buf[512];
		std::cin.getline(buf, 512);
		checkCmd(std::string(buf));
		_mut.lock();
		exit = _exit;
		_mut.unlock();
	}
}

bool threadInput::getEtat()
{
	bool ret;
	_mut.lock();
	ret = _exit;
	_mut.unlock();
	return ret;
}

void threadInput::setTarget(std::string target)
{
	_target = target;
}
