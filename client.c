#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <errno.h>
#include <sys/socket.h>
#include <sys/types.h>


#First Step will be to create a Socket
int main(int argc, char** argv) {
    // creating the socket
    int net_sock;                                                                                                             //initializing socket
    net_sock = socket(AF_INET, SOCK_STREAM, 0);
    //check socket
    if (net_sock < 0){
    perror("socket error, could not create");
    exit(1);
    }
    printf("TCP socket created");

    //check number of arguments is correct
    if (argc < 3){
        printf("Invalid number of argument, specify ip & port no.\n");
        return 0;
    }

    //adding address for the socket
    struct sockaddr_in addr;
    addr.sin_port= htons(??)        // listening port
    addr.sin_family = AF_INET     // IPv4 address
    addr.sin_addr.s_addr = inet_addr(??)      //helping with figuring IP address

    //set up connection to server
    int conn_stat = connect(net_sock, (struct sockaddr *) &addr, sizeof(addr));
    //since connect returns int value, we can use to check for error
    if (conn_stat < 0){
        perror("error: could not connect \n");
    }
    printf("Connected successfully to port no.: %d\n port);

    //Setting message sending and receiving
    char clientmsg[2048];
    char serverreply[2048];
    int len_msg, bytes_rec, bytes_sen;

    while(1){

        printf("Enter message - ")

        //Sending Message
        len_msg = strlen(clientmsg); //defining parameters
        bytes_sen = send(net_sock, clientmsg, len_msg, 0);
        if (bytes_sen < 0){

            puts("Message not sent. Attempting to send again");
            bytes_sen = send(net_sock, clientmsg, len_msg, 0);
        }
        printf("Client's message:", clientmsg);

        //Receiving Message
        bytes_rec = recv(net_sock, serverreply, 2048, 0);
        if (bytes_rec < 0){

            puts("Message not received. Attempting again");
            bytes_rec = recv(net_sock, serverreply, 2048, 0);
        }

        // Dealing with EOF using fgets


        }



    return 0;
}
