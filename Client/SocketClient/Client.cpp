#include "Client.h"
#include <iostream>


Client::Client(const char* address, int port, size_t sizeByff, void(*getdata)(const char* data, std::string str))
{    
    char buff[sizeByff];
    recvBuff = buff;
    memset(recvBuff, '0', sizeof(recvBuff));
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
       //TODO
    }


    memset(&serv_addr, '0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);

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
        
       recvBuff[n] = 0;
        if(fputs(recvBuff, stdout) == EOF)
        {
            
            if(getdata != NULL)
            {
                auto  error = "\n Error : Fputs error\n";
                getdata(error, "");
            }
            else
            {
                printf("\n Error : Fputs error\n");
            }           
        }
        else if(getdata != NULL)
        {
            std::cout << port << '\n';
            getdata(recvBuff, std::to_string(port));
            close(sockfd);
            break;
        }            
    }

    close(sockfd);

}
