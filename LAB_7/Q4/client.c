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
 	int p;
 	int n1,n2,rb1,rb2; // n1-->first number to send n2--> second number to send, rb--> bytes of message received, sum-->stores sum from server
    // First Number
	printf("\nFirst Number to send: ");
 	scanf("%d",&n1);
 	int cm1=sendto(csid,&n1,sizeof(n1),0,(struct sockaddr*)&tos,sizeof(tos));
    // Second number
 	printf("\nSecond Number to send: ");
 	scanf("%d",&n2);
 	int cm2=sendto(csid,&n2,sizeof(n2),0,(struct sockaddr*)&tos,sizeof(tos));
    //checking if both messages are correctly sent
	if(cm1==0 || cm2==0){
	 	printf("\nMessage at client side not found");
		exit(0);
 	}		 
 	p=sizeof(tos);
 	rb1=recvfrom(csid,&n1,100,0,(struct sockaddr *)&tos,&p);
 	rb2=recvfrom(csid,&n2,100,0,(struct sockaddr *)&tos,&p);
 	if(rb1==0 || rb2==0){
 		printf("\nMessage received at client side failed");
 		exit(0);
 	}
 	printf("After swapping value of N1 : %d\n",n1);
 	printf("After swapping value of N2 : %d\n",n2);
	close(csid);
	return 0;
}
