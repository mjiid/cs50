#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    int key= atoi(argv[1]);
    if(argc<2)
    {
        printf("Error \n");
        return 1;
    }
    else if(48 + key<48 || 48 + key >57)
    {
        printf("Usage: ./caesar key \n");
        return 1;
    }
    else
    {
        string plaintext=get_string("plaintext : ");
        for (int i = 0, n = strlen(plaintext);i<n;i++)
        {
            if(((int) plaintext[i] >= 65 && (int) plaintext[i] <= 90) || ((int) plaintext[i] >= 97 && (int) plaintext[i] <= 122))
            {
                while(key >=26){
                    key=key - 26;
                }
                if(key<26-(int) plaintext[i])
                {
                    plaintext[i]=(char) ((int) plaintext[i] + key);
                }else{
                    
                }
            }
        }
        printf("Cipher text: %s",plaintext);
    }
}