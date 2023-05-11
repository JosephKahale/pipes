#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>

int main(){
    int sockets[2], child;
    
    if(socketpair(AF_UNIX, SOCK_STREAM, 0, sockets) < 0){
        printf("Cant open socket pair.");
    }

    if((child = fork()) == -1){
        printf("Error reading message from stream.");
    }
    else if(child){
        close(sockets[0]);
    }
    int one = socket(int domain, int type, int protocol)
}