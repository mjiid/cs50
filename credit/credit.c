#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(void)
{
    long cardNum=0;
    cardNum=get_long("Enter your credit card number: \n");
    int numDig=floor(log10(labs( cardNum)) )+1;
    if(numDIg<13 || numDig>16 || numDig==14){
        printf("INVALID");
    }

}