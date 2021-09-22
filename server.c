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

    if(readData!=-1){
        return readData;
    }else{
        perror("Error in read");

        //need a while loop here?
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

    struct addrinfo serv;
    struct addrinfo *servinfo;
    memset(&serv, 0, sizeof hints);
    serv.ai_family = AF_INET; //using IPv4 for this project
    serv.ai_socktype = SOCK_STREAM; //used for TCP socket stream

    status=getaddrinfo(NULL, "8080", &serv, &servinfo);
    if(status!=0){
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
        exit(1);
    }

    //socket section
    int socket = socket(servinfo->ai_family, servinfo->ai_socktype, offsetof);
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

    //listen section
    int listen = listen(socket, 10);
    if(listen==-1){
        perror("cannot listen");
        exit(-1);
    }

    //accept section
    int accept = accept(socket, (struc))
}
