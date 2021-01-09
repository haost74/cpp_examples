#include "server.h"

#include <iostream>

void thread_task(){}

void server() {

    int conn{-1};
    //printf("%d\n",AF_INET);
    //printf("%d\n",SOCK_STREAM);
    int ss = socket(AF_INET, SOCK_STREAM, 0);
    //printf("%d\n",ss);
    struct sockaddr_in server_sockaddr;
    server_sockaddr.sin_family = AF_INET;
    server_sockaddr.sin_port = htons(PORT);
    //printf("%d\n",INADDR_ANY);
    server_sockaddr.sin_addr.s_addr = inet_addr("192.168.1.72");//htonl(INADDR_ANY);
    if(bind(ss, (struct sockaddr* ) &server_sockaddr, sizeof(server_sockaddr))==-1) {
        perror("bind");
        exit(1);
    }
    if(listen(ss, QUEUE) == -1) {
        perror("listen");
        exit(1);
    }

    int i(0);
    while(1) {

    struct sockaddr_in client_addr;
    socklen_t length = sizeof(client_addr);
    /// Successful return of non-negative descriptor, error Return-1
    conn = accept(ss, (struct sockaddr*)&client_addr, &length);
    if( conn < 0 ) {
        perror("connect");
        exit(1);
    }

    char buffer[2048];
    //Create another thread
    //std::thread t(thread_task);
    //t.join();
    //char buf[1024];
    //Main thread
    

        // memset(buf, 0 ,sizeof(buf));
        // if(fgets(buf, sizeof(buf),stdin) != NULL) {
        //     send(conn, buf, sizeof(buf), 0);    
        // }


        memset(buffer, 0 ,sizeof(buffer));
        int len = recv(conn, buffer, sizeof(buffer), 0);
        if(strcmp(buffer, "exit\n") == 0) break;
        
        std::string str(buffer);
        if(str.length() > 0)
        std::cout << str <<  '\n';

        //printf("%s", buffer);
        //You have to return data to make a complete request.
        //send(conn, buffer, len , 0);
        send(conn, "client", len , 0);
    }
    close(conn);
    close(ss);
}