#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>


class Client
{
    private:
      int sockfd = 0, n = 0;
      char* recvBuff;
      struct sockaddr_in serv_addr;
    public:
    explicit Client(char* address, int port, size_t sizeByff);  
};