#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char** argv)
{
    string key=argv[1];
    int keylength=strlen(key);
    if(argc<3) // the user doesn't provide a key at all or more than one key.
    {
        printf("Usage: ./substitution key\n");
        exit(1);
    }
}