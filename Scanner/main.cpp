#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#include <iostream>
#include <string>


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