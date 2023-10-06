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
    cli.sin_port=9002;

    servaddr.sin_family=AF_INET;
    servaddr.sin_addr.s_addr=inet_addr("127.0.1.1");
    servaddr.sin_port=9000;

    int con_status=connect(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr));
    if(con_status==-1){
        printf("Connection with the server failed.\n");
        exit(0);
    }
    printf("Client 2 connected to the server.\n");
    // char buff[]="Hell";
    // send(sockfd,buff,sizeof(buff),0);
    // recv(sockfd,buff,sizeof(buff),0);
    int n2;
    printf("\nEnter the number to send: ");
    scanf("%d",&n2);
    if(send(sockfd,&n2,sizeof(n2),0)<0){
        printf("Failed to send message..\n");
        exit(0);
    }
    printf("\nMessage sent from Client 2: %d\n",n2);
    if(recv(sockfd,&n2,sizeof(n2),0)<0){
        printf("\nFailed to receive message..\n");
        exit(0);
    }
    printf("\nCurrent Value of n2: %d\n",n2);

    char buff[100];
    if(recv(sockfd,buff,sizeof(buff),0)<0){
        printf("\nFailed to receive message..\n");
        exit(0);
    }
    printf("Message from server : %s\n",buff);
    close(sockfd);
}