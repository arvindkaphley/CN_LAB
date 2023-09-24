#include<sys/socket.h>
#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<unistd.h>
int main(){
    int csid;
    csid=socket(AF_INET,SOCK_DGRAM,0);
    if(csid==-1){
        printf("Error creating the Client Socket");
        exit(0);
    }
    printf("A socket for Client is created\n");
    // 18-08-2023
    struct sockaddr_in cadd;
    cadd.sin_family=AF_INET;
    cadd.sin_port=9000;
    cadd.sin_addr.s_addr=inet_addr("127.0.1.1");
    int cs=bind(csid,(struct sockaddr *)&cadd,sizeof(cadd));
    if(cs==-1){
        printf("Error binding in Client Side");
        exit(0);
    }
    printf("Binding Successful in Client Side");

    struct sockaddr_in tos;
    tos.sin_family = AF_INET;
    tos.sin_port=9001;
    tos.sin_addr.s_addr=inet_addr("127.0.1.1");
    printf("\nEnter a message: ");
    char ca[100];
    gets(ca);
    int cb=sendto(csid,ca,sizeof(ca),0,(struct sockaddr*)&tos,sizeof(tos));
    if(cb==0){
        printf("\nNo message sent");
        exit(0);
    }
    printf("\n Message sent successfully");
    printf("\n %d bytes of message sent",cb);
    int p=sizeof(tos);
    cb=recvfrom(csid,ca,100,0,(struct sockaddr *)&tos,&p);
    printf("\nClient Received Message: %s\n",ca);
    close(csid);
    return 0;
}
