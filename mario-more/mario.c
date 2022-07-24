
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height = 0;
    while(height >8 || height <1){
        height = get_int("Enter the height that you want: \n");
    }
    for(int i=0; i < height; i++)
    {
        for(int j=0; j<=height*2 + 2; j++)
        {
           if(j<height){
                if(height-j-1 > i){
                    printf(" ");
                }else
                {
                    printf("#");
                }
           }else
           {
            if(j==height+1 || j==height +2){
                printf(" ");
            }else{
                if(j<height + 4 +i && j>height){
                    printf("#");
                }
            }
           }
        }
        printf("\n");
    }

}