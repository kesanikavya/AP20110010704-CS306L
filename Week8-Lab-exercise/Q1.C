#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
int i=0,top=0;
char stack[20],ip[20];

void push(char c)
{
	if (top>=20)
		printf("Stack Overflow");
	else
		stack[top++]=c;
}

void pop(void)
{
	if(top<0)
		printf("Stack underflow");
	else
		top--;
}

void error(void)
{
printf("\n\nSyntax Error!!!! String is invalid\n");
getch();
exit(0);
}

int main()
{
int n;

printf("The given grammar is\n\n");
printf("S -> aBa\n");
printf("B -> bB | epsilon \n\n");
printf("Enter the string to be parsed:\n");
scanf("%s",ip);
n=strlen(ip);
ip[n]='$';
ip[n+1]='\0';
push('$');
push('S');
while(ip[i]!='\0')
{ if(ip[i]=='$' && stack[top-1]=='$')
  {
	printf("\n\n Successful parsing of string \n");
	return(1);
  }
  else
	if(ip[i]==stack[top-1])
	{
	   printf("\nmatch of %c occured ",ip[i]);
	   i++;pop();
	}
	else
	{
		if(stack[top-1]=='S' && ip[i]=='a')
		{
		       printf(" \n S ->aBa");
		       pop();
		       push('a');
 		       push('B');
                       push('a');
		}
		else
		if(stack[top-1]=='B' && ip[i]=='b')
		{
			printf("\n B ->bB");
			pop();push('B');push('b');
		}
		     else
		       if(stack[top-1]=='B' && ip[i]=='a')
		       {
			printf("\n B -> epsilon");
			pop();
		       }
		       else
			error();
	}
 }
}//end of main
 117  
Week8-Lab-Exercise/Q2.c
@@ -0,0 +1,117 @@
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
int i=0,top=0;
char stack[20],ip[20];

void push(char c)
{
	if (top>=20)
		printf("Stack Overflow");
	else
		stack[top++]=c;
}

void pop(void)
{
	if(top<0)
		printf("Stack underflow");
	else
		top--;
}

void error(void)
{
printf("\n\nSyntax Error!!!! String is invalid\n");
getch();
exit(0);
}

int main()
{
int n;

printf("The given grammar is\n\n");
printf("E -> TEdash\n");
printf("Edash -> +TEdash | epsilon \n\n");
printf("T -> FTdash \n\n");
printf("Tdash -> *FTdash | epsilon\n\n");
printf("F -> (E) | d \n\n");
printf("Enter the string to be parsed:\n");
scanf("%s",ip);
n=strlen(ip);
ip[n]='$';
ip[n+1]='\0';
push('$');
push('E');
while(ip[i]!='\0')
{ if(ip[i]=='$' && stack[top-1]=='$')
  {
	printf("\n\n Successful parsing of string \n");
	return(1);
  }
  else
	if(ip[i]==stack[top-1])
	{
	   printf("\nmatch of %c occured ",ip[i]);
	   i++;pop();
	}
	else
	{
		if(stack[top-1]=='E' && (ip[i]=='d' || ip[i]=='('))
		{
		       printf(" \n E->TEdash");
		       pop();
		       push('a');
 		       push('T');
		}
		else
		if(stack[top-1]=='a' && ip[i]=='+')
		{
			printf("\n Edash->+TEdash");
			pop();
            push('a');
            push('T');
            push('+');
		}
		     else
		       if(stack[top-1]=='a' && (ip[i]==')' || ip[i]=='$'))
		       {
			     printf("\n Edash->epsilon");
			     pop();
		       }
               else if(stack[top-1]=='T' && (ip[i]=='d' || ip[i]=='(')){
                 printf("\n T->FTdash");
                 pop();
                 push('b');
                 push('F');
               }
               else if(stack[top-1]=='b' && (ip[i]=='+' || ip[i]==')' || ip[i]=='$')){
                printf("\n Tdash->epsilon");
                pop();
               }
               else if(stack[top-1]=='b' && ip[i]=='*'){
                printf("\n Tdash->*FTdash");
                pop();
                push('b');
                push('F');
                push('*');
               }
               else if(stack[top-1]=='F' && ip[i]=='d'){
                printf("\n F->id");
                pop();
                push('d');
               }
               else if(stack[top-1]=='F' && ip[i]=='('){
                printf("\n F->(E)");
                pop();
                push(')');
                push('E');
                push('(');
               } 
		       else
			error();
	}
 }
}//end of main