#ifndef CLIENTSCOEKT_H
#define CLIENTSCOEKT_H

#include <iostream>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <cmath>

#include <vector>
#include <cstring>
#include <stdio.h>


class ClientSocket
{
private:
    int client;
    int portNumber = 5463;
    int buffSize = 40;
    char buffer[40];
    char collectData[1];
    struct sockaddr_in server_addr;
 
public:
    ClientSocket(int port);
    ~ClientSocket();
    char* recieveMessageFromServer();
    bool connectToServer();

};

#endif
