#include<stdio.h>
int main (void)
{
    char exp[100];
    int res=-1, lock=0;
    printf("\nEnter the expression: ");
    scanf("%s",&exp);
    res=tautalogy(exp,0,strlen(exp));

    if(res==0)
        prinf("Not a tautology!");
    else
        prinf("It's a tautology!");
    return 0;
}

int tautalogy(char exp[],int l, int h)
{

    for(int index=0; index<strlen(exp), i++)
        {
            if(exp[index] == '(')
            {
                //search for respective ')' and call this function with that set of exp recursively
            }

            if(exp[index] == '&' || exp[index] == '&')
            {
                //get last two chars at both left and right.
                //search for ! in both sides two chars
                //perform operation (| or &) based on value
                //increment i to the position after the processed variable

            }

        }
}
