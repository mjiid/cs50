#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if(argc!=2) // the user doesn't provide a key at all or more than one key.
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if(strlen(argv[1])!=26) // the user provide a key with a length less than or greater than 26.
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    else // the key contains a number or contains a repeated character.
    {
        string key=argv[1];
        int keylength=strlen(key);
        for(int i = 0;i<keylength;i++)
        {
            if(!(isalpha(key[i])))
            {
                printf("The key must contain only characters!\n");
                return 1;
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
        // the user provided a valid key:
        string plaintext=get_string("Plaintext: ");
        for (int i = 0,n=strlen(plaintext);i<n;i++)
        {
                if(isupper(plaintext[i]))
                {
                    plaintext[i] = toupper(key[(int) plaintext[i] - 65]);
                }
                else if (islower(plaintext[i]))
                {
                    plaintext[i] = tolower(key[(int) plaintext[i] - 97]);
                }
                else
                {
                    continue;
                }
        }
        printf("ciphertext: %s\n",plaintext);
    }
    return 0;
}