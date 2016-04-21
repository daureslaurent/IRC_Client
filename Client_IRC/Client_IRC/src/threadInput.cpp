#include "threadInput.h"



bool threadInput::checkCmd(std::string inData)
{
	if ((inData.size() >= 1) && (inData[0] != '/'))
		_net.Send(inData + "\r\n");
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
	_exit = false;
	_thread.join();
}

void threadInput::Dojob()
{
	while (_exit)
	{
		char	buf[1024];
		std::cin.getline(buf, 1024);
		checkCmd(std::string(buf));
	}
}
