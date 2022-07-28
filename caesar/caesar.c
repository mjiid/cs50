#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    int key= atoi(argv[1]);
    if(argc<2)
    {
        printf("Error \n");
        return 1;
    }
    else if((int) key<48 || (int) key >57)
    {
        printf("Usage: ./caesar key \n");
        return 1;
    }
    else
    {
        string plaintext=get_string("plaintext : ");
        for (int i = 0, n = strlen(plaintext);i<n;i++)
        {
            if((int) plaintext[i]  )
        }
    }
}