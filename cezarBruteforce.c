#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 1000
#define ALPHABET_SIZE 26

char* decipher(char* cipher, int key)
{
    int length = strlen(cipher);
    char* text = (char*)malloc(sizeof(char)*(length+1));

    for(int i = 0; i < length; i++)
    {
        if(cipher[i] >= 'a' && cipher[i] <= 'z')
        {
            text[i] = ((cipher[i] - 'a' ) - key + ALPHABET_SIZE) % ALPHABET_SIZE + 'a';
        }
        
        else if(cipher[i] >= 'A' && cipher[i] <= 'Z')
        {
            text[i] = ((cipher[i] - 'A' ) -key + ALPHABET_SIZE) % ALPHABET_SIZE + 'A';
        }
        else if(cipher[i] >= '0' && cipher[i] <= '9' )
        {
            text[i] = ((cipher[i] - '0') - key + 10) % 10 + '0';
        }
        else
        {
            text[i] = cipher[i];
        }
    }

    return text;
}

int main()
{
    char cipher[MAXN];
    fgets(cipher, MAXN, stdin);

    for(int key = 0; key < ALPHABET_SIZE; key++)
    {
        char* text = decipher(cipher,key);
        printf("Key: %d, Text: %s\n",key,text);
        free(text);
        
    }
    return EXIT_SUCCESS;
}