#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    //key validation:
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    else
    {
        //the key contains 26 characters, but it might contain numbers etc, and also repeated characters.
        string key = argv[1];
        for (int i = 0, n = strlen(key); i < n; i++)
        {
            int counter = 0;
            if (!isalpha(key[i]))
            {
                printf("Key must contain 26 characters.\n");
                return 1;
            }
            else
            {
                //check if a character shows up more than once in the key.
                for (int j = i + 1; j < n; j++)
                {
                    if (key[j] == key[i])
                    {
                        counter++;
                    }
                }
                if (counter >= 1)
                {
                    printf("Key must contain 26 unique characters.\n");
                    return 1;
                }
            }
        }

        // now that the key is valid, let's implement the algorithm:

        printf("plaintext:  ");
        string plaintext = get_string("");
        string ciphertext = plaintext;

        // change every character to the corresponding value.
        for (int i = 0, n = strlen(plaintext); i < n; i++)
        {
            if (isalpha(plaintext[i]))
            {
                if (isupper(plaintext[i]))
                {
                    ciphertext[i] = toupper(key[(int) ciphertext[i] - 65]);
                }
                else
                {
                    ciphertext[i] = tolower(key[(int) ciphertext[i] - 97]);
                }
            }
        }
        printf("ciphertext: %s\n", ciphertext);
        return 0;
    }
}