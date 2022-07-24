#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    long cardNum=0;
    cardNum=get_long("Enter your credit card number: \n");
    int numDig=floor(log10(labs( cardNum)) )+1;
    if(numDIg<13 || numDig>16 || numDIg==14){
        printf("INVALID");
    }

}