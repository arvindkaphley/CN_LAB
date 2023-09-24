#include<sys/socket.h>
#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>
int main(){
    int csid;
    csid=socket(AF_INET,SOCK_DGRAM,0);
    if(csid==-1){
        printf("Error creating the Client Socket");
        exit(0);
    }
    printf("A socket for Client is created\n");
    return 0;
}
