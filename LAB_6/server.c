#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>

int main(){
 	int ssid,ss;
 	char sa[100];
 	ssid=socket(AF_INET,SOCK_DGRAM,0);
 	if(ssid==-1){
 		printf("\nsocket for Server application could not be created successfully\n");
 		exit(0);
 	}

 	printf("\nSocket for server application is initialized successfully\n");
 	struct sockaddr_in sadd;
 	sadd.sin_family=AF_INET;
 	sadd.sin_port=9004;
 	sadd.sin_addr.s_addr=inet_addr("127.0.1.1");
 	ss=bind(ssid,(struct sockaddr*)&sadd,sizeof(sadd));
 	if(ss==-1){
 		printf("\nNo binding done at server side");
 		exit(0);
 	}
 	printf("\nBinding successful server side");
 	struct sockaddr_in frc;
 	int k=sizeof(frc); 
 	while(1){ 
	 	int sb=recvfrom(ssid,sa,100,0,(struct sockaddr*)&frc,&k);
	 	if(sb==0){
	 		printf("\nServer not received");
	 		exit(0);
	 	}
	 	printf("\n Server received : %s",sa);	
	 	if(strcmp(sa,"BYE")==0){
	 		break;
	 	}		
	 	printf("\nServer wants to send:");
	 	scanf("%s",sa);
	 	sb=sendto(ssid,sa,sizeof(sa),0,(struct sockaddr *)&frc,sizeof(frc));
	 	if(sb==0){
	 	printf("\nServer Message not sent");
	 	exit(0);
	 	}
	 	printf("server sent:%s",sa);
	 	}
 	close(ssid);
	 return 0;
}
