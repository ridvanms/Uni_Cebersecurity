#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool isPrime(int number){
    bool prime = true;
    int end = sqrt(number);
    
    for(int i = 2; i <= end;i++){
        if(i % number == 0){
            prime = false;
            break;
        }
    }
    return prime;
}

int main(){
    printf("Check a number whether it is prime : ");
    int number = 0;
    scanf("%d",&number);
    if(isPrime(number)){
       printf("The number %d is prime",number); 
    }else{
        printf("The number %d is NOT prime",number);
    }
    return EXIT_SUCCESS;
}