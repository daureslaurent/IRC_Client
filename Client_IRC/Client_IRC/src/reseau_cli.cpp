#include "reseau_cli.h"

reseau::reseau()
{
}


reseau::~reseau()
{
}

bool reseau::Init(std::string addr, int port)
{
#ifdef _WIN32
	WSADATA WSAData;
	if (WSAStartup(MAKEWORD(2, 0), &WSAData) != 0)
	{
		std::cout << "WSAStartup failed : " << errno << std::endl;
		WSACleanup();
		return false;
	}
#endif

	int		cl_sock;
	struct sockaddr_in cl_addr;
	struct hostent *hostinfo;

	//Create socket
	if ((cl_sock = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	{
		std::cout << "Socket FAIL" << std::endl;
		return false;
	}
	//Get Hostinfo
	hostinfo = gethostbyname(addr.c_str());

	//Fill out the local socket addr info
	cl_addr.sin_family = AF_INET;
	if (hostinfo == NULL)
		cl_addr.sin_addr.s_addr = inet_addr(addr.c_str());
	else
		cl_addr.sin_addr = *(in_addr *)hostinfo->h_addr;
	cl_addr.sin_port = htons(port);

	size_t	server_len = sizeof(cl_addr);

	if (connect(cl_sock, (sockaddr *)&cl_addr, server_len) == -1)
	{
		std::cout << "Erreur Conect" << std::endl;
		return false;
	}
	_socket = cl_sock;
	return true;
}

void reseau::Send(std::string msg)
{
	//std::cout << "Send[" << msg << "]" << std::endl;
	sendto(_socket, msg.c_str(), msg.size(), 0, (struct sockaddr *)&_serv, sizeof(_serv));
}

std::string reseau::Recv()
{
	char	buf[MAX_BUF];
	int ocr;
	struct sockaddr_in client;
#ifdef _WIN32
	int		sock_l = sizeof(client);
#else
	socklen_t		sock_l = sizeof(client);
#endif

	ocr = recvfrom(_socket, (char*)&buf, MAX_BUF-1, 0, (sockaddr*)&client, &sock_l);
	if (ocr == -1)
		return "ERR";
	else
		buf[ocr] = 0;
	//std::cout << "Recv[" << std::string((char*)&buf) << "]" << std::endl;
	return std::string((char*)&buf);
}

void reseau::close_net()
{
#ifdef _WIN32
	closesocket(_socket);
	WSACleanup();
#else
	close(_socket);
#endif
}

int reseau::string_to_int(std::string req, std::string end)
{
	int	end_int;
	size_t p0 = req.find(end);

	if (p0 != std::string::npos)
	{
		req.erase(req.begin() + p0, req.end());
		end_int = std::atoi(req.c_str());
		return end_int;
	}
	else
		return -1;
}
