#include "Client.h"
#include <iostream>


Client::Client(const char* address, int port, size_t sizeByff)
{
    std::cout << 1024 << '\n';
    char buff[sizeByff];
    recvBuff = buff;
    memset(recvBuff, '0', sizeof(recvBuff));
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
       //TODO
    }


    std::cout << 1025 << '\n';
    memset(&serv_addr, '0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);

    std::cout << 1026 << '\n';
    if(inet_pton(AF_INET, address, &serv_addr.sin_addr)<=0)
    {
       //TODO
    }

    if( connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        //TODO
    }

    
    
    while ((n = read(sockfd, recvBuff, sizeof(recvBuff)-1)) > 0)
    {
        close(sockfd);
       recvBuff[n] = 0;
        if(fputs(recvBuff, stdout) == EOF)
        {
            printf("\n Error : Fputs error\n");
        }

        std::cout << n << '\n';

    }

    close(sockfd);

}
