#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>

int main(){
    int sockfd,confd,len;
    struct sockaddr_in servaddr,cli;

    sockfd=socket(AF_INET,SOCK_STREAM,0);
    if(sockfd==-1){
        printf("Socket creation failed\n");
        exit(0);
    }
    else
        printf("Socket successfully created\n");

    servaddr.sin_family=AF_INET;
    servaddr.sin_addr.s_addr=inet_addr("127.0.1.1");
    servaddr.sin_port=9000;

    if(bind(sockfd, (struct sockaddr*)&servaddr,sizeof(servaddr))!=0){
        printf("Socket Binding Unsuccessful.\n");
        exit(0);
    }
    printf("Socket successfully binded.\n");

    if((listen(sockfd,5))!=0){
        printf("Listen Failed.\n");
        exit(0);
    }
    len=sizeof(cli);

    confd=accept(sockfd,(struct sockaddr*)&cli,&len);
    if(confd<0){
        printf("Server accept failed\n");
        exit(0);
    }
    else
        printf("Server accept the client.\n");

    // char buf[20];
    // char buf2[]="Server";
    // recv(confd,buf,sizeof(buf),0);
    // printf("%s",buf);
    // send(confd,buf2,sizeof(buf2),0);
    close(sockfd);
}