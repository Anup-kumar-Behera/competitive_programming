#include<stdio.h>
#include<string.h>
#include<stdbool.h>
bool is_accepted(char s[],int dfa[][2])
{
   int n=strlen(s);
    int state[n+1];

    state[0]=0;
    int i;

    for(i=1;i<=n;i++)
    {
        state[i]=dfa[state[i-1]][s[i-1]-'0'];
    }
    for(i=0;i<=n;i++)
    {
        printf("%d ",state[i]);
    }
    printf("\n");
    if(state[n]==3)
        return true;
    return false;
}
int main()
{
    int dfa[4][2];//dfa for accepting strings with odd zeros an even ones

    dfa[0][0] = dfa[2][1] = 3;
    dfa[1][0] = dfa[3][1] = 2;
    dfa[2][0] = dfa[0][1] = 1;
    dfa[3][0] = dfa[1][1] = 0;

    char str[100];
    printf("enter string :");
    scanf("%s",str);

    is_accepted(str,dfa)?printf("string is accepted."):printf("string is rejected");

    return 0;
}
