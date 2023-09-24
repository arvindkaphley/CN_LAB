#include<sys/types.h>
#include<sys/socket.h>
#include <stdio.h>
#include<stdlib.h>
int main(){
    int ssid;
    ssid=socket(AF_INET,SOCK_DGRAM,0);
    if(ssid==-1){
        printf("Error creating the server socket");
        exit(0);
    }
    printf("A socket for server is created\n");
    return 0;
}
