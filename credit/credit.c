#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(void)
{
    long cardNum=0;
    int sumOfProducts=0;
    cardNum=get_long("Enter your credit card number: \n");
    //Check if the number contains 13, 15 or 16 digits
    int numDig=floor(log10(labs( cardNum)) )+1;
    if(numDig<13 || numDig>16 || numDig==14){
        printf("INVALID\n");
    }
    //calculate the sum of the products:
    int sum=0;
    int total=0;
    for(int i=0;i<numDig;i++){
        int remain=0;
        int num=0;
        int rem=0;
        remain= cardNum % 10;
        cardNum=cardNum/10;
        if(i%2){
            num=remain;
            printf("%i\n",num);
        }
        total=sum;
        total+=num;
        while(num>0){
            num=2*num;
            rem=num%10;
            num=num/10;
            sum += rem;
        }

    }
    printf("%i\n",total);
}