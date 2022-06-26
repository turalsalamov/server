#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include "server.h"

int main() {

    // Declearing the variables
    int socketH, port;
    addressStruct address, clientAddress;
    struct msghdr message;

    // Getting the port number in order to bind it with socket listen incoming requests
    printf("Specify the port number: ");
    scanf("%d", &port);
    
    // Creating the socket
    socketH = socket(PF_INET, SOCK_STREAM, 0);
    if (socketH >= 0) {
        printf("[+] The socket is created!\n");
        address.sin_family = AF_INET;
        address.sin_port = htons(port);
        address.sin_addr.s_addr = inet_addr("127.0.0.1");
        int bindingStatus = bind(socketH, (struct sockaddr *) &address, sizeof(address));
        if (bindingStatus >= 0) {
            printf("[+] Binding operation is successfull!\n");
            // After having the successfull binding, listening starts
            int listeningStatus = listen(socketH, 2);
            // Testing if the listening is successfull
            if (listeningStatus >= 0) {
                printf("[+] The socket is listening for connection...\n");
                
                while (1) {
                    if (recvmsg(socketH, (struct msghdr *) &message, 0) >= 0) {
                        printf("%s", message.msg_name);
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