// Define a structure Student and another structure Result using nested structure

#include <stdio.h>

struct Student{
    int roll;
    char name[10];
    struct Result{
        int sub[3];
        int total;
    }result;
};

int main(){

    struct Student s1;
    printf("Enter the name of the student & roll no:\n");
    scanf("%s",&s1.name);
    scanf("%d",&s1.roll);
    s1.result.total=0;
    for(int i=0;i<3;i++){
        printf("Enter mark in Sub %d :",i+1);
        scanf("%d",&s1.result.sub[i]);
        s1.result.total+=s1.result.sub[i];
    }
    printf("\nName: %s Roll no: %d\n",s1.name,s1.roll);
    printf("Results: \n");
    for(int i=0;i<3;i++){
        printf("Sub %d: %d ",i+1,s1.result.sub[i]);
    }
    printf("\nTotal Marks: %d ",s1.result.total);
    return 0;
}