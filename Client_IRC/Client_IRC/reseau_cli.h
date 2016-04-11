
#ifndef RESEAU_CLI
#define RESEAU_CLI
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#ifdef _WIN32
#pragma comment(lib, "ws2_32.lib")
#include <winsock2.h>
#else
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#endif
#include <errno.h>
#include <iostream>
#include <time.h>
#include <sys/types.h>
#include <string>
#include <vector>
#include <sstream>


#define		MAX_BUF 512

class reseau
{
public:
	reseau();
	~reseau();

	bool		Init(std::string, int);
	void		Send(std::string);
	std::string Recv();
	int			string_to_int(std::string req, std::string end);
	void		close_net();
private:

	int					_socket;
	struct sockaddr_in	_serv;
};
#endif
