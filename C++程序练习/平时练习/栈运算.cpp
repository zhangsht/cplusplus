#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define ERR -1
#define MAX 100 /*定义堆栈的大小*/
int stack[MAX]; /*用一维数组定义堆栈*/
int top=0; /*定义堆栈指示*/

int push(int i) /*存储运算数,入栈操作*/
{
if(top <MAX)
{
stack[++top]=i; /*堆栈仍有空间，栈顶指示上移一个位置*/
return 0;
}
else
{
printf( "The stack is full ");
return ERR;
}
}
int pop() /*取出运算数，出栈操作*/
{
int var; /*定义待返回的栈顶元素*/
if(top!=NULL) /*堆栈中仍有元素*/
{
var=stack[top--]; /*堆栈指示下移一个位置*/
return var; /*返回栈顶元素*/
}
else
printf( "The stack is empty!\n ");
return ERR;
}
int main()
{
int m,n;
char l;
int a,b,c;
int k;
do{
printf( "\tAriothmatic Operate simulator\n "); /*给出提示信息*/
printf( "\n\tPlease input first number: "); /*输入第一个运算数*/
scanf( "%d ",&m);
push(m); /*第一个运算数入栈*/
printf( "\n\tPlease input second number: "); /*输入第二个运算数*/
scanf( "%d ",&n);
push(n); /*第二个运算数入栈*/
printf( "\n\tChoose operator(+/-/*//): ");}
