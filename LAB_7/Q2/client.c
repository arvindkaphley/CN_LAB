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
 		printf("\nSocket Creation in Client Failed\n");
 		exit(0);
 	}
 	printf("\nSocket Created Successfully in Client\n");
 	struct sockaddr_in cadd;
 	cadd.sin_family=AF_INET;
 	cadd.sin_port=9005;
 	cadd.sin_addr.s_addr=inet_addr("127.0.1.1");
 	cs=bind(csid,(struct sockaddr*)&cadd,sizeof(cadd));
 	if(cs==-1){
 		printf("\nNo binding done at Client side");
 		exit(0);
 	}
 	printf("\nBinding successful in Client side");
 	struct sockaddr_in tos;
 	tos.sin_family=AF_INET;
 	tos.sin_port=9004;
 	tos.sin_addr.s_addr=inet_addr("127.0.1.1");
 	int p,count;
 	char str[10];
	printf("\nString to Send: ");
 	gets(str);
 	int cm1=sendto(csid,str,sizeof(str),0,(struct sockaddr*)&tos,sizeof(tos));
	if(cm1==0){
	 	printf("\nMessage at client side not found");
		exit(0);
 	}		 
 	// printf("\nClient sent : %d",ca);
 	p=sizeof(tos);
 	int rb=recvfrom(csid,&count,100,0,(struct sockaddr *)&tos,&p);
 	if(rb==0){
 		printf("\nMessage received at client side failed");
 		exit(0);
 	}
 	printf("\n Vowel Count : %d/n",count);
	close(csid);
	return 0;
}
