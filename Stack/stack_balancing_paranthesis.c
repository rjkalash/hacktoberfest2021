#include<stdio.h>
#include<string.h>

struct Stack
{
    char stack[100];
    int sp;
}s;

int IsEmpty()
{
    if(s.sp==-1)
    return 1;
    else
    return 0;    
}

void push(char a)
{
    s.stack[++s.sp]=a;
}

void pop()
{
    s.sp--;
    /*char ch=s.stack[s.sp--];
    printf("Popped character is : %c",ch);*/
}

int CheckBracket(char c[])
{
    int flag=1;
    for(int i=0;c[i]!='\0';i++)
    {
        if(c[i]=='(')
        push('(');
        else
        {
            if(IsEmpty())
            {
                flag=0;
                break;
            }
            else
            {
                pop();
            }
        }
    }
    if(IsEmpty() && flag==1)
    printf("Balanced\n");
    else
    printf("Unbalanced\n");
}

int main()
{
    s.sp=-1;
    char c[100];
    printf("Enter string : \n");
    gets(c);
    CheckBracket(c);
    return 0;
}
