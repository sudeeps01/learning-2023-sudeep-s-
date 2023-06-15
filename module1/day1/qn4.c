#include<stdio.h>
int main()
{
    int a,b,c;
    char opr;
    printf("enter the first number\n");
    scanf("%d",&a);
    printf("enter the operand\n");
    scanf("%c",&opr);
    printf("enter the second number\n");
    scanf("%d",&b);
    if(opr=='+'){
        c=a+b;
        printf("the answer is %d\n",c);
    }
    if(opr=='-'){
        c=a-b;
        printf("the answer is %d\n",c);
    }
    if(opr=='*'){
        c=a*b;
        printf("the answer is %d\n",c);
    }
    if(opr=='/'){
        c=a/b;
         printf("the answer is %d\n",c);
    }
    if(opr=='%'){
        c=a%b;
         printf("the answer is %d\n",c);
    }
    else{
        printf("invalid operator\n");
    }
    return 0;
}