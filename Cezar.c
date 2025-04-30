#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 1000

char* cezar_encryption(char* plaintext,int key){
    int textLength = strlen(plaintext);
    char* cipher = (char*) malloc(sizeof(char) * (textLength + 1));

    for(int i = 0;i < textLength;i++){
        if(plaintext[i] >= 'a' && plaintext[i] <= 'z'){
            cipher[i] = (plaintext[i] - 'a' +key)%26 + 'a';
        }else if(plaintext[i] >= 'A' && plaintext[i] <= 'Z'){
            cipher[i] = (plaintext[i] - 'A' + key)%26 + 'A';
        }else if(plaintext[i] >= '0' && plaintext[i] <= '9'){
            cipher[i] = (plaintext[i] - '0' + key)%10 + '0';
        }else{
            cipher[i] = plaintext[i];
        }
    }
    return cipher;
}

int main(){
    int key = 0;
    char plaintext[MAXN];
    printf("Text to encypt: ");
    fgets(plaintext,MAXN,stdin);

    printf("Add the key: ");
    scanf("%d",&key);
    
    char* cipher = cezar_encryption(plaintext,key);
    printf("The encypted text: %s",cipher);

    return EXIT_SUCCESS;

}