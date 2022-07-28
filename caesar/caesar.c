#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if(argc<2)
    {
        printf("Error \n");
        return 1;
    }else
    {
        int key= atoi(argv[1]);
        printf("%i\n",key);
    }
}