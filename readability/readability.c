#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
size_t strlen(const char *s);

int main(void)
{
    string text=get_string("Text: ");
    printf("%s\n",text);
    float words=1,letters=0,sentences=0;
    int grade=0;
    for( int i=0,n=strlen(text);i<n;i++)
    {
        if(text[i]=='.' || text[i]=='?'|| text[i]=='!')
        {
            sentences++;
        }else if(text[i]==' ')
        {
            words++;
        }else if((int)text[i]!=39)
        {
            letters++;
        }
    }
    float L= (letters / words ) *100, S=(sentences/words) *100;
    grade=round(0.0588 * L - 0.296 * S - 15.8);
    if(grade<16)
    {
        printf("Grade %i\n",grade);
    }else
    {
        printf("Grade 16+\n");
    }
}