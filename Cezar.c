#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 1000

char* cezarCipher(char* text,int key)
{
    int length = strlen(text);

    char* cipher = (char*)malloc(sizeof(char)*(length+1));

    for(int i = 0;i <= length;i++)
    {
        if(text[i] >= 'a' && text[i] <= 'z')
        {
            cipher[i]=((text[i] -'a' )+key)%26 + 'a';
        }
        else if(text[i] >= 'A' && text[i] <= 'Z')
        {
            cipher[i] = ((text[i] - 'A' )+key)%26 + 'A';
        }
        else if(text[i] >= '0' && text[i] <= '9')
        {
            cipher[i] = ((text[i] - '0')+key)%10 + '0';
        }
        else 
        {
            cipher[i] = text[i];
        }
    }
    return cipher;
}

int main()
{
    char text[MAXN];
    fgets(text,MAXN,stdin);

    int key;
    scanf("%d",&key);
    
    char* cipher = cezarCipher(text,key);
    printf("%s",cipher);

    FILE* fp = fopen("cipher.txt","wb");
    fprintf(fp,"%s",cipher);
    fclose(fp);

    return EXIT_SUCCESS;
}