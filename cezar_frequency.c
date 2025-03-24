#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAXN 1000
#define ALPHABET_SIZE 26
#define COMMON_COUNT 10

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

int* count_frequencies(char* cipher)
{
    int* frequency = (int*)malloc(sizeof(int)*ALPHABET_SIZE);
    memset(frequency,0,sizeof(int)*ALPHABET_SIZE);
    int length = strlen(cipher);

    for(int i = 0;i <= length;i++)
    {
        int position = tolower(cipher[i]) - 'a';
        frequency[position]++;
    }
    return frequency;
}

int getMaxIndex(int* frequency)
{
    int maxIndex = 0;
    for(int i = 0; i < ALPHABET_SIZE; i++)
    {
        if(frequency[i] > frequency[maxIndex])
        {
            maxIndex = i;
        }
    }
    return maxIndex;
}

int main()
{
    char cipher[MAXN];
    fgets(cipher,MAXN,stdin);
    char maxLetter = getMaxIndex(count_frequencies(cipher)) + 'a';
    char commonLetters[COMMON_COUNT] = {'e','t','a','o','i','n','s','h','r','d'};
    
    for(int i = 0; i < COMMON_COUNT; i++)
    {
        int key = abs(maxLetter - commonLetters[i]);
        char* text = decipher(cipher,key);
        printf("Key = %d, result: %s\n", key,text);
        free(text);
    }
    return EXIT_SUCCESS;
}