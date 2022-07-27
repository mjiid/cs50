#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string text=get_string("Text: ");
    int words=0,letters=0,sentences=0,Grad;
    for( int i=0,n=strlen(text);i<n;i++)
    {
        if(text[i]=='.' || text[i]=='?'|| text[i]=='!')
        {
            sentences++;
        }else if(text[i]==' ')
        {
            words++;
        }else
        {
            letters++;
        }
    }
    return
}