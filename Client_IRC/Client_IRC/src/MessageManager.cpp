#include "MessageManager.h"



MessageManager::MessageManager()
{
}


MessageManager::~MessageManager()
{
}

void MessageManager::parse(std::string data)
{
	std::istringstream	iss(data);
	std::string			line;

	while (std::getline(iss, line, '\r'))
	{
		Message	newelem;
		if (line.compare("\n") != 0)
		{
			if (line[0] == '\n')
				line.erase(line.begin());
			newelem.data = line;
			if (line.find("PRIVMSG") != std::string::npos)
			{
				line.erase(line.begin());
				std::string from = line.substr(0, line.find("!"));
				newelem.from = from;
				std::string to = line.substr(line.find("PRIVMSG") + 8, (line.find(":") - 1) - (line.find("PRIVMSG") + 8));
				newelem.to = to;
				std::string msg = line.substr(line.find(":") + 1);
				std::cout << "from[" << from << "]to[" << to << "]msg[" << msg << "]" << std::endl;
				newelem.data = msg;
				newelem.headCode = 1001;
			}
			else
				newelem.headCode = util::takeNbr(line);
			_list.push_back(newelem);
		}
	}
}

bool MessageManager::getLoop()
{
	return (_list.size() > 0) ? true : false;
}

Message MessageManager::exec()
{
	if (_list.size() > 0)
	{
		Message	tmp = _list[0];
		_list.erase(_list.begin());
		return tmp;
	}
	return Message();
}
