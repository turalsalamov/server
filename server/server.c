#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include "server.h"
#include "logs.c"

int main() {

/*
    The dedicated port will be also assigned with protocol and the validation will be handled in 
    protocols.c
*/

    // Declearing the variables
    int socketH, port;
    addressStruct address;
    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = inet_addr("127.0.0.1");
    char buffer[1024] = {0};

    // Getting the port number in order to bind it with socket listen incoming requests
    printf("Specify the port number: ");
    scanf("%d", &port);
    
    // Creating the socket
    socketH = socket(PF_INET, SOCK_STREAM, 0);
    if (socketH >= 0) {
        printf("[+] The socket is created!\n");
        
        int bindingStatus = bind(socketH, (struct sockaddr *) &address, sizeof(address));
        if (bindingStatus >= 0) {
            printf("[+] Binding operation is successfull!\n");
            // After having the successfull binding, listening starts
            int listeningStatus = listen(socketH, 3);

            //LOGGING ->  Testing if the listening is successfull
            char *listening = "Listening status: ";
            char status = (listeningStatus + '0');
            asInfo(listening, status, sizeof(listening));

            // Accepting the connection regarding to listening status
            if (listeningStatus >= 0) {
                printf("[+] The socket is listening for connection...\n");
                while (1) {
                    printf("We are in loop!");
                    int socketForTransfer = accept(socketH, NULL, NULL);
                    // LOGGING -> Testing if the accepting the request is successfull
                    char *socketFT = "Transfer socket status: ";
                    char status = (listeningStatus + '0');
                    asInfo(socketFT, status, sizeof(socketFT));
                    if (socketForTransfer >= 0) {
                        printf("[+] Socket for data transfer is created!\n");
                        int reading = read(socketForTransfer, buffer, 1024);
                        printf("%s\n", buffer);
                        // send(socketForTransfer, "Hello\n", 7, 0);
                        printf("[+] Message is sent...\n");
                        close(socketForTransfer);
                    }
                }
            } else {
                perror("[-] There is an error in listening!\n");
            }
        } else {
            perror("[-] There is a problem with binding!\n");
        }
    } else {
        perror("[-] There is a problem with socket!\n");
    }

    return 0;
}
