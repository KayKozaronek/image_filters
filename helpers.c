#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int average = (int) nearbyint((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int originalRed = image[i][j].rgbtRed;
            int originalGreen = image[i][j].rgbtGreen;
            int originalBlue = image[i][j].rgbtBlue;

            int sepiaRed = (int) round((0.393 * originalRed + 0.769 * originalGreen + 0.189 * originalBlue));
            int sepiaGreen = (int) round((0.349 * originalRed + 0.686 * originalGreen + 0.168 * originalBlue));
            int sepiaBlue = (int) round((0.272 * originalRed + 0.534 * originalGreen + 0.131 * originalBlue));

            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        int arrayRed[width];
        int arrayGreen[width];
        int arrayBlue[width];

        for (int j = 0; j < width; j++)
        {
            arrayRed[width - 1 - j] = image[i][j].rgbtRed;
            arrayGreen[width - 1 - j] = image[i][j].rgbtGreen;
            arrayBlue[width - 1 - j] = image[i][j].rgbtBlue;
        }

        for (int k = 0; k < width; k++)
        {
            image[i][k].rgbtRed = arrayRed[k];
            image[i][k].rgbtGreen = arrayGreen[k];
            image[i][k].rgbtBlue = arrayBlue[k];
        }
    }
    return;
}

// Blur image
const int BLUR = 3;

void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE new_image[height][width];
    double average_blue, average_green, average_red;
    int stat;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            average_blue = average_green = average_red = stat = 0;
            // Box Blur
            for (int rows = i - ((BLUR - 1) / 2); rows <= i + ((BLUR - 1) / 2); rows++)
            {
                for (int cols = j - ((BLUR - 1) / 2); cols <= j + ((BLUR - 1) / 2); cols++)
                {
                    if ((rows >= 0 && rows < height) && (cols >= 0 && cols < width))
                    {
                        average_blue += image[rows][cols].rgbtBlue;
                        average_green += image[rows][cols].rgbtGreen;
                        average_red += image[rows][cols].rgbtRed;
                        stat++;
                    }
                }
            }
            if (stat != 0)
            {
                average_blue =  round(average_blue / (double) stat);
                average_green = round(average_green / (double) stat);
                average_red = round(average_red / (double) stat);
                new_image[i][j].rgbtBlue = average_blue;
                new_image[i][j].rgbtGreen = average_green;
                new_image[i][j].rgbtRed = average_red;
            }
            else
            {
                return;
            }
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = new_image[i][j];
        }
    }
    return;
}