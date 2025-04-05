#include <stdio.h>
#include <stdlib.h>

int NOD(int a,int b)
{
    while(a != b)
    {
        if(a > b)
        {
            a = a-b;
        }
        else{
            b = b-a;
        }
    }
    return a;
}

int main(){
    int a = 0,b=0;
    printf("Insert a: ");
    scanf("%d",&a);
    printf("Insert b: ");
    scanf("%d",&b);

    int result = NOD(a,b);
    printf("THE NOD of %d and %d is: %d",a,b,result);

    return EXIT_SUCCESS;
    
}