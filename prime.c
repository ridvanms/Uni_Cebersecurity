#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool isPrime(int num)
{
    bool prime = true;
    int end = sqrt(num);
    for(int i = 2; i<=end;i++)
    {
        if(num % i == 0)
        {
            prime = false;
        }
    }
    return prime;
}

int main()
{
    int num;
    scanf("%d",&num);

    bool res = isPrime(num);
    if(res)
    {
        printf("The number is prime");
    }
    else
    {
        printf("The number is not prime");
    }
    return EXIT_SUCCESS;
}