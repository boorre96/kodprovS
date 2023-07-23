/**
 * The above code is a C++ implementation of a client socket that connects to a server and receives
 * messages from it.
 * 
 * @return The function `recieveMessageFromServerWIN()` returns a pointer to a character array
 * (`char*`).
 */
#define WIN32_LEAN_AND_MEAN

#include "clientSocket.hpp"

#define DEFAULT_PORT 5463

/**
 * The function initializes the Windows socket by calling the WSAStartup function and returns 1 if
 * successful, otherwise returns 0.
 * 
 * @return an integer value. If the WSAStartup function call is successful (iResult is equal to 0), the
 * function will return 1. Otherwise, if the WSAStartup function call fails, the function will return
 * 0.
 */
int ClientSocketWindows::initializeSocketWIN(){

    iResult = WSAStartup(MAKEWORD(2,2), &this->wsaData);
    if(iResult!= 0){
        std::clog << "WSAStartup failed!" << std::endl;
        return 0;
    }
    return 1;
}

/**
 * The function creates a client socket in a Windows environment.
 * 
 * @return an integer value. If the socket creation is successful, it returns 1. If the socket creation
 * fails, it returns 0.
 */
int ClientSocketWindows::createClientSocketWIN()
{
    
   clientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(clientSocket == INVALID_SOCKET){
        std::clog << "Socket faild with error" + WSAGetLastError() << std::endl;
        WSACleanup();
        return 0;
    }
    std::cout << "Client socket created..."<< std::endl;
    return 1;
}

/**
 * The function `connectSocketToServerWIN` connects a client socket to a server using the Windows API.
 * 
 * @return an integer value. If the connection to the server is successful, it returns 1. If there is
 * an error in initializing the socket or creating the client socket, it returns 0.
 */
int ClientSocketWindows::connectSocketToServerWIN(){
    if(initializeSocketWIN() == 0)
        return 0;
    if (createClientSocketWIN() == 0)
        return 0;
    
  
    this->clientService.sin_family = AF_INET;
    this->clientService.sin_addr.s_addr = inet_addr("127.0.0.1");
    this->clientService.sin_port = htons(DEFAULT_PORT);
    
    
    iResult = connect(this->clientSocket,(SOCKADDR *)&clientService, sizeof(clientService));
    if (iResult == SOCKET_ERROR) {
        int error = WSAGetLastError();
        std::clog << "Could not connect to server! Error code: " << error << std::endl;
        closesocket(this->clientSocket);
        this->clientSocket = INVALID_SOCKET;
        WSACleanup();
        return 0;
    }
        std::cout << "Connected to server..." << std::endl;
        return 1;
}



/**
 * The function `recieveMessageFromServerWIN` receives a message from a server using a Windows client
 * socket.
 * 
 * @return a pointer to a character array (string) called "buffer".
 */
char *ClientSocketWindows::recieveMessageFromServerWIN(){
   
    memset(this->buffer, 0, this->buffSize);
    bool slut = true;
    int iteration = 0;
    while (slut){
        recv(this->clientSocket, this->collectData, 1, 0);
        if (this->collectData[0] == '\n'){
            slut = false;
        }
        else{
            this->buffer[iteration] = this->collectData[0];
            iteration +=1;
        }
    }
    return this->buffer;
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

