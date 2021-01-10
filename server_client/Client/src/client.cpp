#include "client.h"

#include <iostream>

int set_nonblock(int fd){
    int flags;
    #if defined(O_NONBLOCK)
    if(-1 == (flags- fcntl(fd, F_GETFL, 0))) flags = 0;
    return fcntl(fd, F_SETFL, flags | O_NONBLOCK);
    #else
    flags = -1;
    return ioctl(fd, FIOBIO, &flags);
    #endif
}


int Send()
{
    signal(SIGPIPE, SIG_IGN);
    int sock = 0, valread; 
    struct sockaddr_in serv_addr; 
    auto hello = "Hello from client"; 
    char buffer[2048] = {0}; 
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
    { 
        printf("\n Socket creation error \n"); 
        return -1; 
    } 

    //---------------------------------------------------------------------------------

     const int opt = 1;
     setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
     setsockopt(sock, SOL_SOCKET, SO_REUSEPORT, &opt, sizeof(opt));

    //--------------------------------------------------------------------------------- 

   
    serv_addr.sin_family = AF_INET; 
    serv_addr.sin_port = htons(MYPORT); 
       
    // Convert IPv4 and IPv6 addresses from text to binary form 
    if(inet_pton(AF_INET, "192.168.1.72", &serv_addr.sin_addr)<=0)  
    { 
        printf("\nInvalid address/ Address not supported \n"); 
        return -1; 
    } 
   
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
    { 
        printf("\nConnection Failed \n"); 
        return -1; 
    } 
    send(sock , hello , strlen(hello) , 0 ); 
    printf("Hello message sent\n"); 
    valread = read( sock , buffer, 1024); 
    //printf("%s\n",buffer ); 

    std::cout << buffer << " " << "-----" << '\n';
    return 0;
}
