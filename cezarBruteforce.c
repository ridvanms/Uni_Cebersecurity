#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 1000
#define alphabetSize 26

char* cezar_decrypt(char* cipher,int key){
    int cipherLength = strlen(cipher);
    char* text = (char*) malloc(sizeof(char) * (cipherLength + 1));

    for(int i = 0;i < cipherLength;i++){
        if(cipher[i] >= 'a' && cipher[i] <= 'z'){
            text[i] = (cipher[i] - 'a' - key + alphabetSize)%alphabetSize + 'a';
        }else if(cipher[i] >= 'A' && cipher[i] <= 'Z'){
            text[i] = (cipher[i] - 'A' - key + alphabetSize)%alphabetSize + 'A';
        }else if(cipher[i] >= '0' && cipher[i] <= '9'){
            text[i] = (cipher[i] - '0' - key + 10)%10 + '0';
        }else{
            text[i] = cipher[i];
        }
    }
    text[cipherLength] = '\0';
    return text;
}

int main(){
    char cipher[MAXN];
    fgets(cipher,MAXN,stdin);

    for(int key = 0;key <= alphabetSize; key++){
        char* text = cezar_decrypt(cipher,key);
        printf("key: %d, Text: %s\n",key,text);
        free(text);
    }
    return EXIT_SUCCESS;
}