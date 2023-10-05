#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>


int main(){
    int sockfd,confd;
    struct sockaddr_in servaddr,cli;

    sockfd=socket(AF_INET,SOCK_STREAM,0);
    if(sockfd==-1){
        printf("Socket Creation Failed\n");
        exit(0);
    }
    printf("Socket Successfully Created..\n");
    cli.sin_family=AF_INET;
    cli.sin_addr.s_addr=inet_addr("127.0.1.1");
    cli.sin_port=9001;

    servaddr.sin_family=AF_INET;
    servaddr.sin_addr.s_addr=inet_addr("127.0.1.1");
    servaddr.sin_port=9000;

    int con_status=connect(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr));
    if(con_status==-1){
        printf("Connection with the server failed.\n");
        exit(0);
    }
    printf("Connected to the server.\n");
    // char buff[]="Hell";
    // send(sockfd,buff,sizeof(buff),0);
    // recv(sockfd,buff,sizeof(buff),0);
    close(sockfd);
}