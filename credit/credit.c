#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(void)
{
    long cardNum=0;
    cardNum=get_long("Enter your credit card number: \n");
    //Check if the number contains 13, 15 or 16 digits
    int numDig=floor(log10(labs( cardNum)) )+1;
    if(numDig<13 || numDig>16 || numDig==14){
        printf("INVALID\n");
    }
    //calculate the sum of the products:
    for(int i=0; i<numDig;i++){
        int remain = cardNum%10;
        printf("%i\n",remain);
        cardNum=
    }

}