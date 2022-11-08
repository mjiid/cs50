#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);

int main(void)
{
    string text = get_string("Text : ");
    int letters = count_letters(text);
    int words = count_words(text);
    printf("%d\n",letters);
    printf("%d\n",words);

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
    int num = 0;
    int space = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == ' ' && space == 0)
        {
            num++;
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
    return num;
}
