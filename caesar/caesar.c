#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool only_digits(string anykey);
int main(int argc, string argv[])
{
    string key= argv[1];
    if(argc<2)
    {
        printf("Error \n");
        return 1;
    }
    else if(only_digits(key) || argc>2)
    {
        printf("Usage: ./caesar key \n");
        return 1;
    }
    else
    {
        int keyint=atoi(key);
        string plaintext=get_string("plaintext : ");
        string ciphertext;
        for (int i = 0, n = strlen(plaintext);i<n;i++)
        {
            if(((int) plaintext[i] >= 65 && (int) plaintext[i] <= 90) || ((int) plaintext[i] >= 97 && (int) plaintext[i] <= 122))
            {
                while (keyint >=26)
                {
                    keyint = keyint - 26;
                }

            }
        }
        printf("the key is : %s",key);
    }
}

bool only_digits(string anykey)
{
    for (int i =0 , n = strlen(anykey);i<n;i++)
    {
        if((int) anykey[i] +48>48 || (int) anykey[i] +48<57)
        {
            return false;
        }
    }
    return true;
}