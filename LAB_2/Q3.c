// Write a C program to extract each byte from a given number and store them in seperate character variables 
// and print the content of those variables

#include <stdio.h>
int main(){
    int n;
    printf("Enter an integer: \n");
    scanf("%d",&n);
    int bytes[4];
    for(int i=0;i<4;i++){
        n >>= (i*8);
        bytes[i] = (n & 0XFF);
    }
    for(int i=0;i<4;i++){
        printf("The digit in %d byte : %d\n",i,bytes[i]);
    }
    return 0;
}

