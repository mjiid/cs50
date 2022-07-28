#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    int key= atoi(argv[1]);
    int *keyAdd= &key;
    printf("%u\n",keyAdd);
    if(keyAdd==NULL){
        printf("Error");
    }
    string plaintext=get_string("Plaintext: ");
}