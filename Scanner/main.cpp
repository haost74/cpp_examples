#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <fcntl.h>

#include <iostream>
#include <string>

void non_blocking_socket(char* addr, int port);
int main()
{

   struct addrinfo hints, *res;
 int sockfd;
 // сначала заполнить адресные структуры с помощью getaddrinfo():
memset(&hints, 0, sizeof hints);
hints.ai_family = AF_UNSPEC;
 hints.ai_socktype = SOCK_STREAM;
 getaddrinfo("80.87.197.181", "22", &hints, &res);
 // создать сокет:
 sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
 // подключить!
int isConn = connect(sockfd, res->ai_addr, res->ai_addrlen); 
    
    std::cout << isConn << '\n';
   
    return 0;
}

void non_blocking_socket(char* addr, int port)
{
	int sockfd;
	struct addrinfo hints, *res;

	memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;

	getaddrinfo(addr, std::to_string(port).c_str(), &hints, &res);

	// make a socket:

	sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
	//fcntl(sockfd, F_SETFL, O_NONBLOCK);

	 fcntl(sockfd, F_SETFL, O_NONBLOCK);

	// connect!

	auto idCon = connect(sockfd, res->ai_addr, res->ai_addrlen);


	 FD_ZERO(&fdset);
	 FD_SET(sockfd, &fdset);
		tv.tv_sec = 7;             /* 10 second timeout */
		tv.tv_usec = 0;

		if (select(sockfd + 1, NULL, &fdset, NULL, &tv) == 1)
		{
			int so_error;
			socklen_t len = sizeof so_error;
			 getsockopt(sockfd, SOL_SOCKET, SO_ERROR, &so_error, &len);
			 if (so_error == 0) {
				printf("%s:%d is open\n", addr, port);
			}
		}

	std::cout << idCon << '\n';

	close(sockfd);
	close(idCon);
	freeaddrinfo(res); // free the linked list
}