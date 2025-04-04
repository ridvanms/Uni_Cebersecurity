#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool* eratosten(int n )
{
    bool* seive = (bool*)malloc(sizeof(bool) * (n + 1));
    memset(seive,false,(n+1) * sizeof(bool));
    for(int i = 2;i <= n; i++)
    {
        if(seive[i] == false)
        {
            for(int j = i + i ;j <= n; j+=i)
            {
                seive[j] = true;
            }
        }
    }
    return seive;
}


void printNumbers(bool* seive,int n)
{
    for(int i = 2;i <= n;i++)
    {
        if(!seive[i])
        {
            printf("%d ",i);
        }
    }
}

int main()
{
    int n;
    scanf("%d",&n);

    bool* seive = eratosten(n);
    printNumbers(seive,n);
    return EXIT_SUCCESS;
}