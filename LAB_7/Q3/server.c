#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>
int add(int *arr,int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    return sum;
}
int main(){
 	int ssid,ss;
 	ssid=socket(AF_INET,SOCK_DGRAM,0);
 	if(ssid==-1){
 		printf("\nSocket for Server application not created\n");
 		exit(0);
 	}

 	printf("\nSocket for server application initialized successfully\n");
 	struct sockaddr_in sadd;
 	sadd.sin_family=AF_INET;
 	sadd.sin_port=9004;
 	sadd.sin_addr.s_addr=inet_addr("127.0.1.1");
 	ss=bind(ssid,(struct sockaddr*)&sadd,sizeof(sadd));
 	if(ss==-1){
 		printf("\nNo binding done at server side");
 		exit(0);
 	}
 	printf("\nBinding successful in Server Side");
    int n;
    int arr[100];
 	struct sockaddr_in frc;
 	int k=sizeof(frc); 
	int srb1=recvfrom(ssid,&n,100,0,(struct sockaddr*)&frc,&k);
	int srb2=recvfrom(ssid,arr,100,0,(struct sockaddr*)&frc,&k);
 	if(srb1==0 || srb2==0){
 		printf("\nServer not received");
 		exit(0);
 	}
    int sum=add(arr,n);
 	int sendBytes=sendto(ssid,&sum,sizeof(sum),0,(struct sockaddr *)&frc,sizeof(frc));
 	if(sendBytes==0){
 	    printf("\nServer Message not sent\n");
 	    exit(0);
 	}
 	close(ssid);
	return 0;
}
