#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    //getting the user input (text):
    string text = get_string("Text : ");
    //evaluate the number of letters, words and sentences:
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);
    //apply the formula:
    float L = ((float) letters / words) * 100;
    float S = ((float) sentences / words) * 100;
    int index = roundf(0.0588 * L - 0.296 * S - 15.8);

    printf("%f\n",L);
    printf("%f\n",S);
    printf("%d\n",index);

    //Output the grade:
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", index);
    }
}





int count_letters(string text)
{
    //computes the number of letters in a string:
    int num = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (islower(text[i]) || isupper(text[i]))
        {
            num++;
        }
    }
    return num;
}

int count_words(string text)
{
    // computes the number of words in a sentence:
    int words = 1;
    int space = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == ' ' && space == 0)
        {
            words++;
            space++;
        }
        else if (text[i] != ' ')
        {
            space = 0;
        }
        else
        {
            continue;
        }
    }
    return words;
}

int count_sentences(string text)
{
    //computes the number of sentences in a text;
    int sentences = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentences++;
        }
    }
    return sentences;
}