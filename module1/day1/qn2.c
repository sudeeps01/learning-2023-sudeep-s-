#include<stdio.h>
int main()
{
    int marks;
    printf("enter the marks of the student");
    scanf("%d",&marks);
    if(marks>=90){ 
        printf("GRADE A");
    }
    if(marks>=75 && marks<=89){
        printf("GRADE B");
    }
    if (marks<=74 && marks>=60){
        printf("GRADE C");
    }
    if (marks<=59 && marks >=50){
        printf("GRADE D");
    }
    else {
        printf("GRADE F");
    }
}