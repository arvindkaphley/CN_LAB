// WAP to swap two numbers

#include <stdio.h>
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int main(){ 
    printf("Enter two numbers : \n");
    int n1,n2;
    scanf("%d%d",&n1,&n2);
    swap(&n1,&n2);
    printf("The numbers after swapping: ");
    printf("\nn1 = %d",n1);
    printf("\nn2 = %d",n2);

}