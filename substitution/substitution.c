#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    string key=argv[1];
    int keylength=strlen(key);
    if(argc!=2) // the user doesn't provide a key at all or more than one key.
    {
        printf("Usage: ./substitution key\n");
        return -1;
    }
    else if(keylength!=26)
    {
        printf("Key must contain 26 characters.\n");
    }
    else if()
    {
        for(int i = 0;i<keylength;i++)
        {
            if(!(isalpha(key[i])))
            {
                printf("The key must contain only characters!\n");
            }
            else
            {
                char c = tolower(key[i]);
                for(int j = i+1; j < keylength;j++)
                {
                    if(tolower(key[j]) == c)
                    {
                        printf("The key must not contain repeated characters\n");
                        return 1;
                    }
                }
            }
        }
    }
}