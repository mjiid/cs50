#include "helpers.h"
#include <math.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int average =  roundf((image[i][j].rgbtBlue + image[i][j].rgbtRed + image[i][j].rgbtGreen) / 3.0);
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width/2; j++)
        {
            BYTE Blue = image[i][j].rgbtBlue;
            BYTE Red = image[i][j].rgbtRed;
            BYTE Green = image[i][j].rgbtGreen;
            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;
            image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
            image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;

            image[i][width - j - 1].rgbtBlue = Blue;
            image[i][width - j - 1].rgbtRed = Red;
            image[i][width - j - 1].rgbtGreen = Green;

        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE newval;
            newval.rgbtBlue = 0;
            newval.rgbtRed = 0;
            newval.rgbtGreen = 0;
            int count = 1.0;
            for (int k = i - 1; k <= i + 1; k++)
            {
                if (k < 0 || k > height)
                {
                    continue;
                }

                for (int l = j - 1; l <= j + 1; l++)
                {
                    if (l < 0 || l > width || (k == i && l == j))
                    {
                        continue;
                    }

                    newval.rgbtBlue += image[k][l].rgbtBlue;
                    newval.rgbtRed += image[k][l].rgbtRed;
                    newval.rgbtGreen += image[k][l].rgbtGreen;
                    count++;
                }
            }
            image[i][j].rgbtBlue = round(newval.rgbtBlue / count);
            image[i][j].rgbtGreen = round(newval.rgbtGreen / count);
            image[i][j].rgbtRed = round(newval.rgbtRed / count);
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
