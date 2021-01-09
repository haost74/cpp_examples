#ifndef __CLIENT_CPP__
#define __CLIENT_CPP__

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/shm.h>

#include <signal.h>

#define MYPORT  7000
#define BUFFER_SIZE 1024

int Send();
int set_nonblock(int id);

#endif