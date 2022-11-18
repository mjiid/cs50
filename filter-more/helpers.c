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
    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, 1}, {0, 0, 0}, {1, 2, 1}};

    RGBTRIPLE temp[height][width];

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
            int sum_gx_red = 0, sum_gy_red = 0;
            int sum_gx_blue = 0, sum_gy_blue = 0;
            int sum_gx_green = 0, sum_gy_green = 0;

            for (int k = i - 1;  k < i + 2; k++)
            {
                if (k < 0 || k >= height)
                {
                    continue;
                }
                for (int l = j - 1; l < j + 2; j++)
                {
                    if (l < 0 || l >= width)
                    {
                        continue;
                    }
                    sum_gx_red += Gx[k][l] * temp[k][l].rgbtRed;
                    sum_gx_blue += Gx[k][l] * temp[k][l].rgbtBlue;
                    sum_gx_green += Gx[k][l] * temp[k][l].rgbtGreen;

                    sum_gy_red += Gy[k][l] * temp[k][l].rgbtRed;
                    sum_gy_blue += Gy[k][l] * temp[k][l].rgbtBlue;
                    sum_gy_green += Gy[k][l] * temp[k][l].rgbtGreen;
                }
            }

            int final_red = sum_gx_red * sum_gx_red + sum_gy_red * sum_gy_red;
            int final_blue = sum_gx_blue * sum_gx_blue + sum_gy_blue * sum_gy_blue;
            int final_green = sum_gx_green * sum_gx_green + sum_gy_green * sum_gy_green;

            if (final_red > 255)
            {
                image[i][j].rgbtRed = 255;
            }
            else
            {
                image[i][j].rgbtRed = final_red;
            }

            if (final_blue > 255)
            {
                image[i][j].rgbtBlue = 255;
            }
            else
            {
                image[i][j].rgbtBlue = final_blue;
            }

            if (final_green > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            else
            {
                image[i][j].rgbtGreen = final_green;
            }

        }
    }


    return;
}
