#include "util.h"

int util::takeNbr(std::string data)
{
	bool		stop = false;
	std::string	nbr= "";
	for (size_t i = 0; i < data.size(); i++)
	{
		if (data[i] >= '0' && data[i] <= '9')
		{
			stop = true;
			nbr += data[i];
		}
		else if (stop)
			return std::atoi(nbr.c_str());
	}
	return -1;
}
