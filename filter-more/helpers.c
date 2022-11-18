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
    // Create temp array
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }
        // Loop through rows
    for (int i = 0; i < height; i++)
    {
        // Loop through columns
        for (int j = 0; j < width; j++)
        {
            // Initialise values
            float sum_red = 0;
            float sum_blue = 0;
            float sum_green = 0;
            int counter = 0;
            // For each pixel, loop vertical and horizontal
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
                    // Otherwise add to sums
                    sum_red += temp[k][l].rgbtRed;
                    sum_blue += temp[k][l].rgbtBlue;
                    sum_green += temp[k][l].rgbtGreen;
                    counter++;
                }
            }
            // Get average and blur image
            image[i][j].rgbtRed = round(sum_red / counter);
            image[i][j].rgbtGreen = round(sum_green / counter);
            image[i][j].rgbtBlue = round(sum_blue / counter);
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j].rgbtBlue = image[i][j].rgbtBlue;
            temp[i][j].rgbtRed = image[i][j].rgbtRed;
            temp[i][j].rgbtGreen = image[i][j].rgbtGreen;
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < height; j++)
        {
            float gx_red = 0, gy_red = 0;
            float gx_blue = 0, gy_blue = 0;
            float gx_green = 0, gy_green = 0;

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

                    gx_red += temp[k][l].rgbtRed * Gx[k - i + 1][l - j + 1];
                    gx_blue += temp[k][l].rgbtBlue * Gx[k - i + 1][l - j + 1];
                    gx_green += temp[k][l].rgbtGreen * Gx[k - i + 1][l - j + 1];

                    gy_red += temp[k][l].rgbtRed * Gy[k - i + 1][l - j + 1];
                    gy_blue += temp[k][l].rgbtBlue * Gy[k - i + 1][l - j + 1];
                    gy_green += temp[k][l].rgbtGreen * Gy[k - i + 1][l - j + 1];

                }
            }

            int final_red = round(sqrt(gx_red * gx_red + gy_red * gy_red));
            int final_blue = round(sqrt(gx_blue * gx_blue + gy_blue * gy_blue));
            int final_green = round(sqrt(gx_green * gx_green + gy_green * gy_green));

            image[i][j].rgbtRed = (final_red > 255) ? 255 : final_red;
            image[i][j].rgbtBlue = (final_blue > 255) ? 255 : final_blue;
            image[i][j].rgbtGreen = (final_green > 255) ? 255 : final_green;
        }
    }




    return;
}
