#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<string.h>
#include<strings.h>
#include<errno.h>
#include<unistd.h>
#include<arpa/inet.h>


// read data/messages from the client
int read(void *buf, int length, int sockfd){

    //use recv function to
    int readData = recv(sockfd, buf, length, 0);

    if(readData != -1){
        return readData;
    }else{
        perror("Error in read, attempting again");

        //need a while loop here?
        while ()
        read(buf,length,sockfd)

    }
}

// write data back to client
int writen(const void *buf, int length, int sockfd){

    int writeData = send(sockfd, buf, length, 0)

    // if no error, return number of bytes
    if(writeData!=-1){
        return writeData;
    }else{
        if(errno == EINTR){
            printf("Slow system call caused interrupted write. Restarting.");
            writen(buf, length, sockfd);
        }
    }

    return -1;
}

int main(int argc, char *argv[]){

    struct addrinfo serv; // server socket address
    struct addrinfo clt_addr; // client socket address
    struct addrinfo *servinfo; //
    memset(&serv, '\0', sizeof (hints));
    serv.ai_family = AF_INET; //using IPv4 for this project
    serv.ai_socktype = SOCK_STREAM; //used for TCP socket stream
    serv.ai_port = htons(atoi(argv[1])); // port
    serv.ai_addr = INADDR_ANY; //IP address to any
    //?? mem set missing
    int pid; // process id for child
    int socket, sock_2; // socket descriptor & new socket for client connection
    char messge[1024], ; //message that will be echoed




    status = getaddrinfo(NULL, "8080", &serv, &servinfo);
    if(status!=0){
        fpr intf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
        exit(1);
    }

    //socket section
    int socket = socket(servinfo->ai_family, servinfo->ai_socktype, 0);
    if(socket == -1){
        perror("cannot return socket descriptor");
        exit(-1);
    }

    //bind section
    int bind =  bind(socket, servinfo->ai_addr, servinfo->ai_addrlen);
    if(bind==-1){
        perror("cannot bind");
        exit(-1);
    }
    printf("Bind(ed) to port");

    //listen section
    int listen = listen(socket, 10);
    if(listen == -1){
        perror("server error: cannot listen");
        exit(-1);
    }
    printf("Listening... \n");

    //accept section
    // while loop for setup to accept connection from client
    while(1){
        sock_2 = accept(socket, (structxx*), sizeof(xx));
        if (sock_2 < 0){
            perror("server error:cannot accept")
        }

        printf("Client Accepted, now connected")
    }

    processid = fork() //child process setup

}


