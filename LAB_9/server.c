#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>

int main(){
    int sockfd,confd1,confd2,confd3,len1,len2,len3;
    int n1,n2;
    struct sockaddr_in servaddr,cli1,cli2,cli3;

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

    if((listen(sockfd,3))!=0){
        printf("Listen Failed.\n");
        exit(0);
    }
    len1=sizeof(cli1);

    confd1=accept(sockfd,(struct sockaddr*)&cli1,&len1);
    if(confd1<0){
        printf("Server accept failed for Client 1\n");
        exit(0);
    }
    else
        printf("Server accepted the Client 1.\n");


    if(recv(confd1,&n1,sizeof(n1),0)<0){
        printf("Couldn't receive message from Client 1\n");
        exit(0);
    }

    

    len2=sizeof(cli2);
    confd2=accept(sockfd,(struct sockaddr*)&cli2,&len2);
    if(confd2<0){
        printf("Server accept failed for Client 2\n");
        exit(0);
    }
    else
        printf("Server accepted the Client 2.\n");

    if(recv(confd2,&n2,sizeof(n1),0)<0){
        printf("Couldn't receive message from Client 2\n");
        exit(0);
    }


    if(send(confd1,&n2,sizeof(n2),0)<0){
        printf("Couldn't send message to Client 1.\n");
        exit(0);
    }

    if(send(confd2,&n1,sizeof(n1),0)<0){
        printf("Couldn't send message to Client 2.\n");
        exit(0);
    }




    len3=sizeof(cli3);
    confd3=accept(sockfd,(struct sockaddr *)&cli3,&len3);
    if(confd3<0){
        printf("Server accept failed for Client 3.\n");
        exit(0);
    }
    else
        printf("Server accepted Client 3.\n");
    char buff[100];
    if(recv(confd3,buff,sizeof(buff),0)<0){
        printf("Couldn't receive message from Client 2\n");
        exit(0);
    }
    if(send(confd2,buff,sizeof(buff),0)<0){
        printf("Couldn't send message to Client 2.\n");
        exit(0);
    }
    // char buf[20];
    // char buf2[]="Server";
    // recv(confd,buf,sizeof(buf),0);
    // printf("%s",buf);
    // send(confd,buf2,sizeof(buf2),0);
    close(sockfd);
}