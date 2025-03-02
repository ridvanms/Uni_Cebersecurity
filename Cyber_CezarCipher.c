#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 1000

char* cezar_cipher(char* str, int key, int encrypt){
    int length = strlen(str);
    char* cipher = (char*)malloc(sizeof(char) * (length + 1));
    
    if(cipher == NULL){
        printf("Memory allocation failed\n");
        exit(1);
    }
    if (!encrypt) {
        key = -key;
    }
    for(int i = 0; i < length; i++){
        if(str[i] >= 'a' && str[i] <= 'z'){
            cipher[i] = ((str[i] - 'a') + key + 26) % 26 + 'a';
        }else if(str[i] >= 'A' && str[i] <= 'Z'){
            cipher[i] = ((str[i] - 'A') + key + 26) % 26 + 'A';
        }else{
            cipher[i] = str[i];
        }
    }
    cipher[length] = '\0';
    return cipher;
}

int main(){
    char str[MAX];
    printf("Enter the string:\n");
    scanf("%s", str);

    printf("Enter the key:\n");
    int key;
    scanf("%d", &key);

    printf("Enter 1 for encryption or 0 for decryption:\n");
    int encrypt;
    scanf("%d", &encrypt);

    char* cipher = cezar_cipher(str, key, encrypt);
    printf("The result text is: %s\n", cipher);
    free(cipher);
    return EXIT_SUCCESS;
}