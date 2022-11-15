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
            float count = 1.0;
            for (int k = i - 1; k <= i + 1; k++)
            {
                for (int l = j - 1; l <= j + 1; j++)
                {
                    if (k < 0 || k > height || l < 0 || l > width)
                    {
                        continue;
                    }
                    else if (k == i && l == j)
                    {
                        continue;
                    }
                    else
                    {
                        image[i][j].rgbtBlue += image[k][l].rgbtBlue;
                        image[i][j].rgbtRed += image[k][l].rgbtRed;
                        image[i][j].rgbtGreen += image[k][l].rgbtGreen;
                        count += 1.0;
                    }
                }
                image[i][j].rgbtBlue = roundf(image[i][j].rgbtBlue / count);
                image[i][j].rgbtRed = roundf(image[i][j].rgbtRed / count);
                image[i][j].rgbtGreen = roundf(image[i][j].rgbtGreen / count);
            }
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
