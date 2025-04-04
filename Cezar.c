#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 1000

char* cezarCipher(char* str,int key)
{
    int length = strlen(str);
    char* cipher = (char*)malloc(sizeof(char) * (length+1));

    for(int i = 0;i < length; i++)
    {
        if(str[i] >= 'a' && str[i] <= 'z')
        {
            cipher[i] = ((str[i] - 'a' )+key)%26 + 'a';
        }
        else if(str[i] >= 'A' && str[i] <= 'Z')
        {
            cipher[i] = ((str[i] - 'A' ) + key)%26 + 'A';
        }
        else if(str[i] >= '0' && str[i] <= '9')
        {
            cipher[i] = ((str[i] - '0' ) + key)%10 + '0';
        }
        else {
            cipher[i] = str[i];
        }
    }
    return cipher;
}


int main()
{
    char str[MAXN];
    fgets(str,MAXN,stdin);

    int key;
    scanf("%d",key);

    char* cipher = cezarCipher(str,key);
    printf("%s",cipher);

    FILE* fp = fopen("cipher.txt","wb");
    fprintf(fp,"%s",cipher);
    fclose(fp);

    return EXIT_SUCCESS;
}