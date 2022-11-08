#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int count_letters(string text);

int main(void)
{
    string text = get_string("Text : ");
    int letters = count_letters(text);
    printf("%d\n",letters);

}



int count_letters(string text)
{
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