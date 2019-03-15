#include "irc_udp.h"

void    client(void) {
    int clientSocket, nBytes;
    char buffer[1024];
    struct sockaddr_in serverAddr;
    socklen_t addr_size;

    /*Create UDP socket*/
    clientSocket = socket(PF_INET, SOCK_DGRAM, 0);

    /*Configure settings in address struct*/
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(4242);
    serverAddr.sin_addr.s_addr = inet_addr("192.168.42.82");
    memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);  

    /*Initialize size variable to be used later on*/
    addr_size = sizeof serverAddr;

    while (1) {
        printf("Type a sentence to send to server:\n");
        fgets(buffer, 1024, stdin);
        printf("You typed: %s",buffer);

        nBytes = strlen(buffer) + 1;

        /*Send message to server*/
        ssize_t rc = sendto(clientSocket, buffer, nBytes, 0, (struct sockaddr *)&serverAddr, addr_size);

        printf("%ld\n", rc);
        if (rc < 0)
            printf ("%s\n", strerror(errno));

        /*Receive message from server*/
        memset(buffer, 0, 1024);
        nBytes = recv(clientSocket, buffer, 1024, 0);

        printf("Received from server: %s\n", buffer);
    }
}