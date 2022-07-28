#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool only_digits(string anykey);
void rotate(string plaintext);
int main(int argc, string argv[])
{
    string k = argv[1];
    if(argc<2 || !(only_digits(k)))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        int keyasnum = atoi(k);
        string plaintext=get_string("Plaintext: ");



    }

    return 0;
}





bool only_digits(string anykey)
{
    for (int i = 0, n= strlen(anykey);i<n;i++)
    {
        int keynum = anykey[i];
        if(keynum <48 || keynum>57)
        {
            return false;
        }
    }
    return true;
}

void rotate(string plaintext)
{
    for (int i = 0, n= strlen(plaintext);i<n;i++)
    {
        
    }
}