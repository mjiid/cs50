#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool only_digits(string anykey);
char rotate(char text,int key);


int main(int argc, string argv[])
{
    string k = argv[1];
    //if the user enters more than 1 command-lines, no one at all or a key with letters in it.
    if(argc!=2 || !(only_digits(k)))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        //Encipher the plaintext by rotating every character.
        int keyasnum = atoi(k);
        string plaintext=get_string("Plaintext: ");
        for(int i =0, n = strlen(plaintext);i<n;i++)
        {
            plaintext[i] = rotate(plaintext[i],keyasnum);
        }
        printf("ciphertext: %s\n",plaintext);
    }
    return 0;
}





bool only_digits(string anykey)
{
    //check for every the key if it's a number or not
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

char rotate(char character,int key)
{
    //if it's not a character then return it as it is:
    if(((int) character <65 || (int) character > 90) && ((int) character <97 || (int) character >122))
    {
        return character;
    }
    //check for lowercase letters:
    else if( (int) character >=65 && (int) character <= 90 )
    {
        int count = (int) character - 65;
        int num=count+key;
        if(num <=26)
        {
            return (char) num +65;
        }
        else
        {
            while(num > 26)
            {
                num = num - 26;
            }
            return (char) num + 65;
        }

    }
    //for uppercase letters:
    else
    {
        int count = (int) character - 97;
        int num = count + key;
        if(num < 26)
        {
            return (char) num + 97;
        }
        else
        {
            while(num >= 26)
            {
                num= num - 26;
            }
            return (char) num + 97;
        }
    }
}