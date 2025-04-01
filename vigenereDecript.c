#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXN 1000

char* vigenereDecript(char* cipher,char* key)
{
    int cipherLength = strlen(cipher);
    int keyLength = strlen(key);
    char* text=(char*)malloc((cipherLength + 1) * sizeof(char));
    memset(text,'\0',sizeof(char)*(cipherLength+1));

    for(int i = 0; i < cipherLength; i++)
    {
        int shift=tolower(key[i%keyLength]) - 'a';
        if(isalpha(cipher[i]))
        {
            if(islower(cipher[i]))
            {
                text[i] = 'a' + (cipher[i] -'a' - shift + 26) %26;
            }
            else
            {
                text[i] = 'A' + (cipher[i] -'A' -shift + 26) % 26;
            }
        }
        else
        {
            text[i] = cipher[i];
        }
    }
    text[cipherLength] = '\0'; // Null-terminate the string
    return text;
}   

int readCipher(char* fname,char* cipher)
{
    FILE* file = fopen(fname,"r");
    if(file == NULL)
    {
        printf("Error opening file" );
        return EXIT_FAILURE;
    }
    if(fgets(cipher, MAXN,file) == NULL)
    {
        printf("Error reading file" );
    }
    fclose(file);
    return EXIT_FAILURE;
}

void writeFile(char* fname,char* text)
{
    FILE* fp = fopen(fname,"w" );
    fprintf(fp,"%s",text);
    fclose(fp);
}

int main()
{
    char cipherFile[MAXN];
    scanf("%s",cipherFile);
    char keyFile[MAXN];
    scanf("%s",keyFile);
    char cipher[MAXN];
    readCipher(cipherFile,cipher);
    char key[MAXN];
    readCipher(keyFile,key);
    char* text = vigenereDecript(cipher,key);
    writeFile("plaintext.txt",text);
    free(text);
    return EXIT_SUCCESS;
}