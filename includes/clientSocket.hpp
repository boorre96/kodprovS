#ifndef CLIENTSCOEKT_H
#define CLIENTSCOEKT_H

// linux Socket
//#include <sys/socket.h>
//#include <netinet/in.h>
//#include <arpa/inet.h>
//#include <netdb.h>
// #include <cmath>
// #include <vector>
// #include <cstring>

#include <iostream>
#include <string.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>

// winSock API
#include <winsock2.h>
#include <ws2tcpip.h>
#include <windows.h>





#include <stdio.h>

#pragma comment(lib, "ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")

/* linux Socket
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
*/

class ClientSocketWindows{
    private:
        WSADATA wsaData;
        SOCKET clientSocket = INVALID_SOCKET;
        sockaddr_in clientService;
        
        char collectData[1];
        char buffer[40];
        int iResult;
        int buffSize = 40;

    public:
        int initializeSocketWIN();
        int createClientSocketWIN();
        int connectSocketToServerWIN();
        char* recieveMessageFromServerWIN();

};

#endif
