#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool only_digits(string anykey);
int main(int argc, string argv[])
{
    string k = argv[1];
    if(argc!=2 || only_digits(k))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }


}



bool only_digits(string anykey)
{
    for (int i = 0, n= strlen(anykey);i<n;i++)
    {
        int keynum = atoi(anykey);
        if(keynum +48<48 || keynum+48<57)
        {
            return false;
        }
    }
    return true;
}