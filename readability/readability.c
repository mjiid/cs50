#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
size_t strlen(const char *s);

int count_words(string text);
int count_letters(string text);
int count_sentences(string text);
int main(void)
{
    string text=get_string("Text: ");
    int grade=0;
    float L=  (count_letters(text) / (float)count_words(text) ) *100;
    float S= (count_sentences(text)/ (float)count_words(text)) *100;
    grade=round(0.0588 * L - 0.296 * S - 15.8);
    if(grade<16 && grade>=1)
    {
        printf("Grade %i\n",grade);
    }else if(grade <1){
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade 16+\n");
    }
}

int count_words(string text)
{
    int words=1;
    for (int i = 0, n = strlen(text); i < n ; i++)
    {
        if(text[i]==' ')
        {
            words++;
        }
    }

    return words;
}
int count_letters(string text)
{
    int letters=0;
    for( int i=0,n=strlen(text);i<n;i++)
    {
        if( ((int)text[i]>=65 && (int) text[i]<=90) || ((int)text[i]>=97 && (int) text[i]<=122) )
        {
            letters++;
        }
    }

    return letters;
}
int count_sentences(string text)
{
    int sentences=0;
    for( int i=0,n=strlen(text);i<n;i++){
        if(text[i]=='.' || text[i]=='?'|| text[i]=='!')
        {
            sentences++;
        }
    }
    return sentences;
}