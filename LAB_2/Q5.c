#include<stdio.h>

int main(){
	int n,lsb,msb;
	printf("Enter the number to be converted to the bytes");
	scanf("%d",&n);
	lsb = n&255;
	msb = (n>>24)&255;
	printf("\nextracted byte from lsb= %d",lsb);
	printf("\nextracted byte from msb= %d",msb);
	printf("\nMemeory representation of the number\n");
	printf("\n ----------------------------------------------- \n");
	printf("\nMemory Address   ->      value");
	printf("\n ----------------------------------------------- \n");
	char *p= (char*)&n;
	
	printf("\n%p 	-> 	%d",p,*(p));
	printf("\n%p 	->	%d",(p+1),*(p+1));
	printf("\n%p 	-> 	%d",(p+2),*(p+2));
	printf("\n%p 	-> 	%d\n\n",(p+3),*(p+3));

    // char c0=n&255;
    // char c1=(n>>8)&255;
    // char c2=(n>>16)&255;
    // char c3=(n>>24)&255;

    // int *ptr = &n;

    // printf("\n%p 	-> 	%d",&c0,c0);
	// printf("\n%p 	->	%d",&c1,c1);
	// printf("\n%p 	-> 	%d",&c2,c2);
	// printf("\n%p 	-> 	%d\n\n",&c3,c3);
	
	if (lsb==*(char*)(p)){
		printf("The LSB of the number is stored at the lowest memory address\nHence, the host is in little Endian");
		printf("\n\nThe number is converted to Big Endian Now\n");
	}
	else{
		printf("The MSB of the number is stored at the lowest memory address\nHence, the host is in Big Endian");
		printf("\n\nThe number is converted to Little Endian Now\n");
	}
	int converted =0;
	
	converted = ((n&0xff)|converted)<<8;
	converted = (((n>>8)&0xff)|converted)<<8;
	converted = (((n>>16)&0xff)|converted)<<8;
	converted = (((n>>24)&0xff)|converted);
	
	printf("\nMemeory representation of the number\n");
	printf("\n ----------------------------------------------- ");
	printf("\nMemory Address  ->           value");
	printf("\n ----------------------------------------------- ");
	p= (char*)&converted;
	
	printf("\n%p	->	%d",p,*(char*)(p));
	printf("\n%p	->	%d",(p+1),*(char *)(p+1));
	printf("\n%p	->	%d",(p+2),*(char*)(p+2));
	printf("\n%p 	->	%d\n\n",(p+3),*(char *)(p+3));
	
	printf("the number is in the format is  %d",converted);	 
}