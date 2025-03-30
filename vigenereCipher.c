#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

char* vigenereEncript(char* plaintext,char* key)
{
    int textLength = strlen(plaintext);
    int keyLength = strlen(key);
    char* cipherText=(char*)malloc(sizeof(char)*textLength+1);
    memset(cipherText,'\0',sizeof(char)*textLength+1);
    for(int i =0;i<textLength;i++)
    {
        int shift=tolower(key[i%keyLength]) - 'a';
        if(isalpha(plaintext[i]))
        {
            if(islower(plaintext[i]))
            {
                cipherText[i] = 'a' + (plaintext[i] -'a' + shift)% 26;
            }
            else
            {
                cipherText[i] = 'A' + (plaintext[i] - 'A' +shift) % 26;
            }
        }
        else
        {
            cipherText[i] = plaintext[i];
        }
    }
    cipherText[textLength] = '\0';
    return cipherText;
}

int readCipher(char* fname,char* cipher)
{
    FILE* file = fopen(fname, "r");
    if(file == NULL)
    {
        printf("Error opening file \n");
        return EXIT_FAILURE;
    }
    if(fgets(cipher,MAX_LENGTH,file) == NULL)
    {
        printf("Error reading file \n");
        return EXIT_FAILURE;
    }
    fclose(file);
    return EXIT_SUCCESS;
}

void writeFile(char* fname,char* text)
{
    FILE* fp = fopen(fname, "wb");
    fprintf(fp,"%s",text);
    fclose(fp);
}

int main()
{
    char textFile[MAX_LENGTH];
    scanf("%s",textFile);
    char keyFile[MAX_LENGTH];
    scanf("%s",keyFile);
    char text[MAX_LENGTH];
    readCipher(textFile,text);
    char key[MAX_LENGTH];
    readCipher(keyFile,key);
    char* cipherText = vigenereEncript(text,key);
    writeFile("cipherText.txt",cipherText);
    free(cipherText);
    return EXIT_SUCCESS;
}