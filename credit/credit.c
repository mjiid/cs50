#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(void)
{
    //get the card number:
    long cardNum=0;
    cardNum=get_long("Enter your credit card number: \n");
    //Check if the number contains 13, 15 or 16 digits if it doesn't then it's invalid :
    int numDig=floor(log10(labs( cardNum)) )+1;
    if(numDig<13 || numDig>16 || numDig==14){
        printf("INVALID\n");
    }
    //when the number contains 13,15 or 16 digits:
    else{
        long card=cardNum; //store the card number for later use.
        //calculate the sum :
        int sumOfProducts=0,sumOfdigits=0,total=0;
        for(int i=0;i<numDig;i++){
            int remain=0;
            int num=0;
            int rem=0;
            remain=cardNum % 10;
            cardNum=cardNum/10;
            if(i%2){
                num=remain;
                num=2*num;
                while(num>0){
                    rem=num%10;
                    num=num/10;
                    sumOfProducts+=rem;
                }
            }else{
                sumOfDigits+=remain;
            }
        }

        total=sumOfProducts+sumOfDigits;
        //Check the type of the card:
        int digits = (int)log10(card);
        int first=(int)(card / pow(10, digits));
        int second=(int) (card/pow(10,digits-1))%10;
        if(!(total%10)){
            if(first==3 &&(second==4 ||second==7)){
                printf("AMEX\n");
            }else if(first == 4 ){
                printf("VISA\n");
            }else if(first==5 && (second ==1 ||second ==2 ||second ==3 ||second ==4 ||second ==5)){
                printf("MASTERCARD\n");
            }else{
                printf("INVALID\n");
            }
        }else{
            printf("INVALID\n");
        }
    }

}