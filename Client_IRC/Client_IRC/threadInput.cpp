#include "threadInput.h"



bool threadInput::checkCmd(std::string inData)
{
	std::cout << "In[" << inData << "]" << std::endl;
	if ((inData.size() >= 1) && (inData[0] != '/'))
	{
		std::cout << "Send msg" << std::endl;
		_net.Send(inData + "\r\n");
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
		int		end;
		std::cin.getline(buf, 1024);
		checkCmd(std::string(buf));
	}
}
