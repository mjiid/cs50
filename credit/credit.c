#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(void)
{
    long cardNum=0;
    cardNum=get_long("Enter your credit card number: \n");
    //Check if the number contains 13, 15 or 16 digits
    int numDig=(int)log10(cardNum);
    if(numDig<13 || numDig>16 || numDig==14){
        printf("INVALID\n");
    }

    //calculate the sum of the products:
    int sum1=0,sum2=0,total=0;
    for(int i=0;i<numDig;i++){
        int remain=0;
        int num=0;
        int rem=0;
        remain= cardNum % 10;
        cardNum=cardNum/10;
        if(i%2){
            num=remain;
            printf("%i\n",num);
            while(num>0){
                num=2*num;
                rem=num%10;
                num=num/10;
                sum1+=rem;
            }
        }else{
            sum2+=remain;
        }
    }
    //First digit of the card number:
    int first=(int)(cardNum / pow(10, numDig));
    total=sum1+sum2-1;
    printf("%i\n",total);
    if(!(total%10)){
        switch(first){
            case 3:
                printf("AMEX");
            break;
            case 5:
                printf("MASTERCARD");
            break;
            case 4:
                printf("VISA");
            break;
            default:
                printf("qskdklqsjdkqsjdkl");
            break;
        }
    }else{
        printf("INVALID\n");
    }
}