#include "helpers.h"
#include <math.h>
#include <stdio.h>
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
    // create a duplicate of the image
    RGBTRIPLE temp[width][height];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float sum_blue = 0;
            float sum_red = 0;
            float sum_green = 0;
            int counter = 0;

            for (int k = i - 1; k <= i + 1; k++)
            {
                if (k < 0 || k >= height)
                {
                    continue;
                }
                for (int l = j - 1; l <= j + 1; l++)
                {
                    if (l < 0 || l >= width)
                    {
                        continue;
                    }
                    
                    sum_blue += temp[k][l].rgbtBlue;
                    sum_red += temp[k][l].rgbtRed;
                    sum_green += temp[k][l].rgbtGreen;
                    counter++;
                }
            }
            image[i][j].rgbtBlue = round(sum_blue / counter);
            image[i][j].rgbtRed = round(sum_red / counter);
            image[i][j].rgbtGreen = round(sum_green / counter);
        }
    }

    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
