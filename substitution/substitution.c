#include <cs50.h>
#include <stdio.h>
#include <string.h>

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
    else
    {
        for(int i = 0;i<keylength;i++)
        {
            if(!(isalpha(key[i])))
            {
                printf("")
            }
        }
    }
}