#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXN 1000

char* vigenere_encrypt(char* plainText,char* key){
    int textLength = strlen(plainText);
    int keyLength = strlen(key);

    char* cipher = (char*)malloc(sizeof(char)* (textLength + 1));
    memset(cipher,'\0',sizeof(char) * (textLength + 1));

    for(int i = 0;i < textLength; i++){
        int shift = tolower(key[i % keyLength]) - 'a';

        if(isalpha(plainText[i])){
            if(islower(plainText[i])){
                cipher[i] = 'a' + (plainText[i] - 'a' + shift) %26;

            }
            else{
                cipher[i] = 'A' + (plainText[i] - 'A' + shift) %26;
            }
        }else{
            cipher[i] = plainText[i];
        }
    }
    cipher[textLength] = '\0';
    return cipher;
}

int readCipher(char* fname,char* cipher){
    FILE* p = fopen(fname,"r");
    
    if(p == NULL){
        printf("Error opening the file.");
        return EXIT_FAILURE;
    }

    if(fgets(cipher,MAXN,p) == NULL){
        printf("Error reading the file");
        return EXIT_FAILURE;
    }

    fclose(p);
    return EXIT_SUCCESS;
}

void writeFile(char* fname, char* text){
    FILE* fp = fopen(fname,"wb");
    fprintf(fp,"%s",text);
    fclose(fp);
}

int main(){
    char textFile[MAXN];
    scanf("%s",&textFile);
    char keyFile[MAXN];
    scanf("%s",&keyFile);
    char text[MAXN];

    readCipher(textFile,text);
    char key[MAXN];
    readCipher(keyFile,key);

    char* cipher = vigenere_encrypt(text,key);
    writeFile("cipher_vig.txt",cipher);
    free(cipher);
    return EXIT_SUCCESS;
}