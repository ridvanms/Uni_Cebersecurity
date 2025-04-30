#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool* eratosten(int n){
    bool* seive = (bool*)malloc(sizeof(bool) * (n + 1));
    memset(seive,false,sizeof(bool) * (n+1));

    for(int i = 2; i <= n; i++){
        if(seive[i] == false){
            for(int j = i+i; j <= n;j += i){
                seive[j]=true;
            }
        }
    }
    return seive;
}

void printNumbers(bool* seive,int n){
    printf("prime numbers are: ");
    for(int i = 2;i<=n;i++){
        if(!seive[i]){
            printf("%d ",i);
        }
    }
}

int main(){
    int number= 0;
    printf("You need to add a number: ");
    scanf("%d",&number);
    bool* seive = eratosten(number);
    printNumbers(seive,number);
    return EXIT_SUCCESS;
}