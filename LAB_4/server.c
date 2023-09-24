#include<sys/types.h>
#include<sys/socket.h>
#include <stdio.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<unistd.h>
int main(){
    int ssid;
    ssid=socket(AF_INET,SOCK_DGRAM,0);
    if(ssid==-1){
        printf("Error creating the server socket");
        exit(0);
    }
    printf("A socket for server is created\n");
    struct sockaddr_in sadd;
    sadd.sin_family=AF_INET;
    sadd.sin_port=9001;
    sadd.sin_addr.s_addr=inet_addr("127.0.1.1");
    int ss=bind(ssid,(struct sockaddr *)&sadd,sizeof(sadd));
    if(ss==-1){
        printf("Error binding in Server Side");
        exit(0);
    }
    printf("Binding Successful in Server Side");

    struct sockaddr_in frc;
    int k=sizeof(frc);
    int sb;
    char sa[100];
    sb=recvfrom(ssid,sa,100,0,(struct sockaddr *)&frc,&k);
    if(sb==0){
        printf("\nNo Message Found");
        exit(0);
    }else{
        printf("\nMessage Successfully Received");
        printf("\nserver received message: %s",sa);
    }
    printf("\nEnter a message to send");
    gets(sa);
    printf("%s",sa);
    sb=sendto(ssid,sa,sizeof(sa),0,(struct sockaddr *)&frc,sizeof(frc));
    printf("\nserver sent : %s\n",sa);
    close(ssid);
    return 0;
}
