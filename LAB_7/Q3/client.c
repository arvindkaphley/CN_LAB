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
 	int n,rb,sum; // n1-->first number to send n2--> second number to send, rb--> bytes of message received, sum-->stores sum from server
    // Size of Array
	printf("\nArray Size: ");
 	scanf("%d",&n);
    int arr[n];
 	int cm1=sendto(csid,&n,sizeof(n),0,(struct sockaddr*)&tos,sizeof(tos));
    // Array
 	printf("\nEnter the array elements: ");
 	for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
 	int cm2=sendto(csid,arr,sizeof(arr),0,(struct sockaddr*)&tos,sizeof(tos));
    //checking if both messages are correctly sent
	if(cm1==0 || cm2==0){
	 	printf("\nMessage at client side not found");
		exit(0);
 	}		 
 	p=sizeof(tos);
 	rb=recvfrom(csid,&sum,100,0,(struct sockaddr *)&tos,&p);
 	if(rb==0){
 		printf("\nMessage received at client side failed");
 		exit(0);
 	}
 	printf("\n Sum From Server to Client : %d/n",sum);
	close(csid);
	return 0;
}
