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
        return 1;
    }
}