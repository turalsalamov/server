#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include "server.h"
#include "logs.c"
#include "webRequestParser.c"

void runningServerUp() {

    // Declearing the variables
    int socketH, port, addressLength, peerAddresslength;
    addressStruct hostAddress, peerAddress;
    char buffer[1024] = {0};
    // Getting the port number in order to bind it with socket listen incoming requests
    printf("Specify the port number: ");
    scanf("%d", &port);

    // Defining the host address attributes
    hostAddress.sin_port = htons(port);
    hostAddress.sin_family = AF_INET;
    hostAddress.sin_addr.s_addr = inet_addr("127.0.0.1");
    
    // Creating the socket
    socketH = socket(PF_INET, SOCK_STREAM, 0);
    if (socketH >= 0) {
        addressLength = sizeof(hostAddress);
        int bindingStatus = bind(socketH, (struct sockaddr*)&hostAddress, addressLength);
        if (bindingStatus >= 0) {

            // After having the successfull binding, listening starts
            int listeningStatus = listen(socketH, 10);

            // Accepting the connection regarding to listening status
            if (listeningStatus >= 0) {
                printf("[+] The socket is listening to %d port!\n", port);
                
                // Starting the loop in order to accept the requests from peers.
                while(1) {
                    int socketForTransfer = accept(socketH, NULL, NULL);
                     if (socketForTransfer >= 0) {
                        int reading = read(socketForTransfer, buffer, 1024);

                        // Identifing the type of web request
                        methodIdentifier(buffer, sizeof(buffer));

                        // Printing the whole request
                        printf("\n");
                        printf("%s\n", buffer);

                        // Sending reponse to the connected peer
                        send(socketForTransfer, "Hello\n", 7, 0);
                        printf("[+] Message is sent...\n");
                        close(socketForTransfer);
                    } else {
                        perror("There is a problem");
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
}

