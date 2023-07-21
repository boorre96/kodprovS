#define WIN32_LEAN_AND_MEAN

#include "clientSocket.hpp"
/*
Initialize Winsock.
Create a socket.
Bind the socket.
Listen on the socket for a client.
Accept a connection from a client.
Receive and send data.
Disconnect.
*/
#define DEFAULT_PORT 5463

int ClientSocketWindows::initializeSocket(){

    /*
    The WSAStartup function is called to initiate use of WS2_32.dll.
    
    The WSADATA structure contains information about the Windows Sockets 
    implementation. The MAKEWORD(2,2) parameter of WSAStartup makes a 
    request for version 2.2 of Winsock on the system, and sets the passed
    version as the highest version of Windows Sockets support that 
    the caller can use.
    */
    iResult = WSAStartup(MAKEWORD(2,2), &this->wsaData);
    if(iResult!= 0){
        std::clog << "WSAStartup failed!" << std::endl;
        return 0;
    }
    return 1;
}

int ClientSocketWindows::createClientSocket()
{
    /*
    This finctions tries to create a socket object that the client is going to use.
    The parameters of the socket:
    AF_INET = 
    SOCK_STREAM = 
    IPROTO_TCP = 
    */
   clientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(clientSocket == INVALID_SOCKET){
        std::cout << "Socket faild with error" + WSAGetLastError() << std::endl;
        WSACleanup();
        return 0;
    }
    std::cout << "Client socket created..."<< std::endl;
    return 1;
}

int ClientSocketWindows::connectSocketToServer(){
    /*
    First set the server characteristics.
    
    */
    this->clientService.sin_family = AF_INET;
    this->clientService.sin_addr.s_addr = inet_addr("127.0.0.1");
    this->clientService.sin_port = htons(DEFAULT_PORT);
    
    /*
    Connect to server.
    */ 
    iResult = connect(this->clientSocket,(SOCKADDR *)&clientService, sizeof(clientService));
    if (iResult == SOCKET_ERROR) {
        int error = WSAGetLastError();
        std::cout << "Could not connect to server! Error code: " << error << std::endl;
        closesocket(this->clientSocket);
        this->clientSocket = INVALID_SOCKET;
        std::cout << "Could not connect to server!"<< std::endl;
        WSACleanup();
        return 0;
    }
        std::cout << "Connected to server..." << std::endl;
        return 1;
}


// ClientSocket::ClientSocket(int port){

//     // init socket / create a client socket
//     this->client = socket(AF_INET, SOCK_STREAM, 0);
    
//     if (client < 0){
//         std::clog << "Error creating socket..." << std::endl;
//     }
//     else{
//         std::cout << "Client socket created..." << std::endl;
//     }
//     this->server_addr.sin_family = AF_INET;
//     this->server_addr.sin_port = htons(port);
//     this->server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
// }
// ClientSocket::~ClientSocket(){
// }

// char *ClientSocket::recieveMessageFromServer()
// {
//     memset(this->buffer, 0, this->buffSize);
//     bool slut = true;
//     int iteration = 0;
//     while (slut)
//     {
//         recv(this->client, this->collectData, 1, 0);
//         if (this->collectData[0] == '\n'){
//             slut = false;
//         }
//         else{
//             this->buffer[iteration] = this->collectData[0];
//             iteration +=1;
//         }
//     }
//     return this->buffer;

// }

// bool ClientSocket::connectToServer(){   
    
//     if (connect(this->client, (struct sockaddr *)&this->server_addr, sizeof(this->server_addr)) < 0){
//         std::clog << "Failed to connect to server.." << std::endl;
//         close(this->client);
//         return false;
//     }
//     else{
//         std::cout << "Connected to server" << std::endl;
//         return true;
//     }
// }

