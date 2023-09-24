#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>

int main(){
 	int csid,cs;
 	csid=socket(AF_INET,SOCK_DGRAM,0);
 	if(csid==-1){
 		printf("\nsocket for client application could not be created successfully\n");
 		exit(0);
 	}
 	printf("\nSocket for client application is initialized successfully\n");
 	struct sockaddr_in cadd;
 	cadd.sin_family=AF_INET;
 	cadd.sin_port=9005;
 	cadd.sin_addr.s_addr=inet_addr("127.0.1.1");
 	cs=bind(csid,(struct sockaddr*)&cadd,sizeof(cadd));
 	if(cs==-1){
 		printf("\nNo binding done at client side");
 		exit(0);
 	}
 	printf("\nBinding successful client side");
 	struct sockaddr_in tos;
 	tos.sin_family=AF_INET;
 	tos.sin_port=9004;
 	tos.sin_addr.s_addr=inet_addr("127.0.1.1");
 	int p;
 	char ca[100];
 	while(1){
	 	printf("\nclient want to send message: ");
	 	scanf("%s",ca);
	 	int cb=sendto(csid,ca,sizeof(ca),0,(struct sockaddr*)&tos,sizeof(tos));
	 	if(cb==0){
	 		printf("\nMessage at client side not found");
	 		exit(0);
	 	}		 
	 	printf("\nClient sent : %s",ca);
	 	p=sizeof(tos);
	 	cb=recvfrom(csid,ca,100,0,(struct sockaddr *)&tos,&p);
	 	if(cb==0){
	 		printf("\nMessage received at client side failed");
	 		exit(0);
	 	}
	 	printf("\n Client received : %s",ca);
	 	if(strcmp(ca,"BYE")==0){
	 		break;
	 	}
	 	}
	close(csid);
	return 0;
}
