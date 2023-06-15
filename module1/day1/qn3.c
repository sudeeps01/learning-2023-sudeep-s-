#include<stdio.h>
int main(){
    int roll,phy,math,chem;
    char name[20];
    printf("enter your roll number\n");
    scanf("%d",&roll);
    printf("enter your name\n");
    scanf("%d",&name);
    printf("enter the marks of physics\n");
    scanf("%d\n",&phy);
    printf("enter the marks of maths\n");
   scanf("%d\n",&math); 
    printf("enter the marks of chemistry\n");
    scanf("%d\n",&chem);
    double per=(phy+math+chem*100)/300;
    printf("student name: %d\n",name[20]);
    printf("student roll number: %d\n",roll);
    printf("student marks in physics,maths and chemistry is %d %d %d\n",phy,math,chem);
    printf("total percentage is  %d\n",per);
    return 0;
}
