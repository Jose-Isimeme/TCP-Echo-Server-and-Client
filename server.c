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
int reader(void *buf, int length, int sockfd){

    //use recv function to
    int readData = recv(sockfd, buf, length, 0);

    while(length!=-1){
        length = recv(sockfd, buf, length, 0);
    }
    return readData;
}

// write data back to client
int writen(const void *buf, int length, int sockfd){

    int writeData = send(sockfd, buf, length, 0);

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

struct addrinfo {
int ai_flags; // AI_PASSIVE, AI_CANONNAME, etc.
int ai_family; // AF_INET, AF_INET6, AF_UNSPEC
int ai_socktype; // SOCK_STREAM, SOCK_DGRAM
int ai_protocol; // use 0 for "any"
size_t ai_addrlen; // size of ai_addr in bytes
struct sockaddr *ai_addr; // struct sockaddr_in or _in6
char *ai_canonname; // full canonical hostname
struct addrinfo *ai_next; // linked list, next node
};

int main(int argc, char *argv[]){

    struct addrinfo serv; // server socket
    struct addrinfo clt_addr; // client socket
    struct addrinfo *servinfo; // point to results
    memset(&serv, '\0', sizeof (serv));
    serv.ai_family = AF_INET; //using IPv4 for this project
    serv.ai_socktype = SOCK_STREAM; //used for TCP socket stream
    serv.ai_addr = INADDR_ANY; //IP address to any
    //?? mem set missing
    int pid; // process id for child
    int socket_1, sock_2; // socket descriptor & new socket for client connection
    char messge[1024]; //echo message

    //socket section
    socket_1 = socket(servinfo->ai_family, servinfo->ai_socktype, 0);
    if(socket_1 == -1){
        perror("cannot return socket descriptor");
        exit(-1);
    }

    //bind section
    int binder =  bind(socket_1, servinfo->ai_addr, servinfo->ai_addrlen);
    if(binder==-1){
        perror("cannot bind");
        exit(-1);
    }
    printf("Bind(ed) to port");

    //listen section
    int listens = listen(socket_1, 10);
    if(listens == -1){
        perror("server error: cannot listen");
        exit(-1);
    }
    printf("Listening... \n");

    //accept section
    // while loop for setup to accept connection from client
    while(1){
        sock_2 = accept(socket_1, servinfo->ai_addr, NULL);
        if (sock_2 < 0){
            perror("server error:cannot accept");
        }
        int pid = fork();
        if(pid > 0){
            printf("Parent");
        }else{
            close(socket_1);
            int mesg = reader(sock_2, messge, 1024);
   
            while(1){
                if (messge <= 0){ 
                    break;
                }
                
                printf("From server: %d byte message coming", mesg);
                int writeb = writen(sock_2, messge, mesg);
                
            }
            close(sock_2);
            exit(0);
        }
    }
    
                
    

}


