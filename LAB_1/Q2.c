#include <stdio.h>

struct Employee{
    char name[20];
    int age;
    char designation[20];
    int salary;
};
void show(struct Employee e){
    printf("\nName: %s",e.name );
    printf("\nAge: %d",e.age );
    printf("\nDesignation: %s",e.designation );
    printf("\nSalary: %d",e.salary );

}
int main(){
    printf("Enter Employee Details: ");
    struct Employee e1;
    struct Employee e2;
    printf("\nEnter name: ");
    scanf("%s",&e1.name);
    printf("\nEnter age: ");
    scanf("%d",&e1.age);
    printf("\nEnter designation: ");
    scanf("%s",&e1.designation);
    printf("\nEnter Salary: ");
    scanf("%d",&e1.salary);
    printf("\nEnter name: ");
    scanf("%s",&e2.name);
    printf("\nEnter age: ");
    scanf("%d",&e2.age);
    printf("\nEnter designation: ");
    scanf("%s",&e2.designation);
    printf("\nEnter Salary: ");
    scanf("%d",&e2.salary);
    show(e1);
    show(e2);
    return 0;
}