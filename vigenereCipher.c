#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define MAXN 1000
char * vigenere_encript(char* plaintext,char* key)
{
    int text_length=strlen(plaintext);
    int key_length=strlen(key);
    char* cipher=(char*)malloc(sizeof(char)*text_length+1);
    memset(cipher,'\0',sizeof(char)*text_length+1);
    for(int i=0;i<text_length;i++)
    {
        int shift=tolower(key[i%key_length])-'a';
        if(isalpha(plaintext[i]))
        {
              if(islower(plaintext[i]))
              {
                cipher[i]='a'+(plaintext[i]-'a'+shift)%26;
              }
              else
              {
                cipher[i]='A'+(plaintext[i]-'A'+shift)%26;
              }
        }
        else
        {
            cipher[i]=plaintext[i];
        }
    }
    cipher[text_length]='\0';
    return cipher;
}
int read_cipher(char * fname,char * cipher)
{
    FILE *p = fopen(fname,"r");
    if(p==NULL)
    {
        printf("Error opening the file");
        return EXIT_FAILURE;
    }
    if(fgets(cipher,MAXN,p)==NULL)
    {
        printf("Error reading the file");
        return EXIT_FAILURE;
    }
    fclose(p);
    return EXIT_SUCCESS;
}
void write_file(char* fname,char*text)
{
 FILE *fp=fopen(fname,"wb");
 fprintf(fp,"%s",text);
 fclose(fp);
}
int main()
{
    char text_file[MAXN];
    scanf("%s",text_file);
    char key_file[MAXN];
    scanf("%s",key_file);
    char text[MAXN];
    read_cipher(text_file,text);
    char key[MAXN];
    read_cipher(key_file,key);
    char * cipher = vigenere_encript(text,key);
    write_file("cipher_vig.txt",cipher);
    free(cipher);
    return EXIT_SUCCESS;
}