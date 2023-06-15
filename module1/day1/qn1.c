#include<stdio.h>
int main()
{
    int a,b;
    printf("enter first number\n");
    scanf("%d",&a);
    printf("enter second number\n");
    scanf("%d",&b);
    if(a>b){
        printf("the largest number is %d",a);
    }
    else{
        printf("the largest number is  %d",b);
    }
    return 0;
}