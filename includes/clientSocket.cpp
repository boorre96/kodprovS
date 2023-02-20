#include "clientSocket.hpp"

ClientSocket::ClientSocket(int port){

    // init socket / create a client socket
    this->client = socket(AF_INET, SOCK_STREAM, 0);
    
    if (client < 0){
        std::clog << "Error creating socket..." << std::endl;
    }
    else{
        std::cout << "Client socket created..." << std::endl;
    }
    this->server_addr.sin_family = AF_INET;
    this->server_addr.sin_port = htons(port);
    this->server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
}
ClientSocket::~ClientSocket(){
}

char *ClientSocket::recieveMessageFromServer()
{
    memset(this->buffer, 0, this->buffSize);
    bool slut = true;
    int iteration = 0;
    while (slut)
    {
        recv(this->client, this->collectData, 1, 0);
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

bool ClientSocket::connectToServer(){   
    
    if (connect(this->client, (struct sockaddr *)&this->server_addr, sizeof(this->server_addr)) < 0){
        std::clog << "Failed to connect to server.." << std::endl;
        close(this->client);
        return false;
    }
    else{
        std::cout << "Connected to server" << std::endl;
        return true;
    }
}

