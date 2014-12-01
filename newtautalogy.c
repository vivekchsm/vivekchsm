#include<stdio.h>
char postfixExpr[100];

int priority(char symbol)
{
    switch(symbol)
    {
    case '(':
        return 0;
    case '|':
        return 1;
    case '&':
        return 2;
    case '!':
        return 3;
    default :
        return 0;
    }
}

void postfixConvert(char expr[])
{
    char stack[1000]; int stackPointer=-1;
    int index,pointer=0;
    char nextvalue;
    char symbol;
    for(index=0;index<strlen(expr)-1;index++)
    {
        symbol=expr[index];
        if(symbol!=' ')
        {
            switch(symbol)
            {
            case '(':
                stack[++stackPointer]=symbol;
                break;
            case ')':
                while((nextvalue=stack[stackPointer--])!='(')
                    postfixExpr[pointer++] = nextvalue;
                break;
            case '|':
            case '&':
            case '!':
                while(stackPointer!=-1 &&  priority(stack[stackPointer])>= priority(symbol))
                    postfixExpr[pointer++]=stack[stackPointer--];
                stack[++stackPointer]=symbol;
                break;
            default:
                postfixExpr[pointer++]=symbol;
            }

        }

    }
    while(stackPointer!=-1)
        postfixExpr[pointer++]=stack[stackPointer--];
    postfixExpr[pointer]='\0';
}
int evaluate(char expr[],int low, int high)
{

}
int main (void)
{
    char expr[100];
    int result=-1;
    printf("\nEnter the expression: ");
    fgets(&expr,100,stdin);
    postfixConvert(expr);
    printf("Postfix: %s",postfixExpr);
    evaluate(postfixExpr, 0, strlen(postfixExpr)-1);

    return 0;
}


