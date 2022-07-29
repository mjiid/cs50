#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    string key=argv[1];
    if(argc!=2) // the user doesn't provide a key at all or more than one key.
    {
        printf("Usage: ./substitution key\n");
        return -1;
    }
    else if(strlen(key)!=26)
    {
        printf("Key must contain 26 characters.\n");
    }
}