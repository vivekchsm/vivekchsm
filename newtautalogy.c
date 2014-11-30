#include<stdio.h>
char stack[1000]; int sp=-1;
char newexp[100];

int pr(char sym)
{
    switch(sym)
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

void postfixconvert(char exp[])
{
    int i,p=0;
    char nextval;
    char sym;
    for(i=0;i<strlen(exp)-1;i++)
    {
        sym=exp[i];
        if(sym!=' ')
        {
            switch(sym)
            {
            case '(':
                stack[++sp]=sym;
                break;
            case ')':
                while((nextval=stack[sp--])!='(')
                    newexp[p++] = nextval;
                break;
            case '|':
            case '&':
            case '!':
                while(sp!=-1 &&  pr(stack[sp])>= pr(sym))
                    newexp[p++]=stack[sp--];
                stack[++sp]=sym;
                break;
            default:
                newexp[p++]=sym;
            }

        }

    }
    while(sp!=-1)
        newexp[p++]=stack[sp--];
    newexp[p]='\0';
}
int evaluate(char temp[],int l, int h)
{

}
int main (void)
{
    char exp[100];
    int res=-1;
    printf("\nEnter the expression: ");
    fgets(&exp,100,stdin);
    postfixconvert(exp);
    evaluate(newexp, 0, strlen(newexp)-1);

    return 0;
}
