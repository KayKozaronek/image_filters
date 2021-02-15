void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE placeholderImg[height][width];
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            // CORNER CASE
            if ((i == 0 && j == 0) || (i == height-1 && j == 0) || (i == 0 && j == (width - 1) ) || (i == (height - 1)  && j == (width - 1) ))
            {
                int avgRed = (int) nearbyint((image[i][j].rgbtRed + image[i][j + 1].rgbtRed +image[i + 1][j].rgbtRed +image[i + 1][j + 1].rgbtRed) / 4);
                int avgGreen = (int) nearbyint((image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen +image[i + 1][j].rgbtGreen +image[i + 1][j + 1].rgbtGreen) / 4);
                int avgBlue = (int) nearbyint((image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue +image[i + 1][j].rgbtBlue +image[i + 1][j + 1].rgbtBlue) / 4);

                placeholderImg[i][j].rgbtRed = avgRed;
                placeholderImg[i][j].rgbtGreen = avgGreen;
                placeholderImg[i][j].rgbtBlue = avgBlue;
                continue;
            }

            // EDGE CASE TOP
            else if ((i == 0) && (!(j == 0 || j == width - 1)))
            {
                int avgRed = (int) nearbyint((image[i][j].rgbtRed + image[i][j + 1].rgbtRed +image[i + 1][j].rgbtRed +image[i + 1][j + 1].rgbtRed +image[i][j - 1].rgbtRed +image[i + 1][j - 1].rgbtRed) / 6);
                int avgGreen = (int) nearbyint((image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen +image[i + 1][j].rgbtGreen +image[i + 1][j + 1].rgbtGreen +image[i][j - 1].rgbtGreen +image[i + 1][j-1].rgbtGreen) / 6);
                int avgBlue = (int) nearbyint((image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue +image[i + 1][j].rgbtBlue +image[i + 1][j + 1].rgbtBlue +image[i][j - 1].rgbtBlue +image[i + 1][j - 1].rgbtBlue) / 6);

                placeholderImg[i][j].rgbtRed = avgRed;
                placeholderImg[i][j].rgbtGreen = avgGreen;
                placeholderImg[i][j].rgbtBlue = avgBlue;
                continue;
            }

            // EDGE CASE BOTTOM
            else if ((i == height - 1) && (!(j == 0 || j == width - 1)))
            {
                int avgRed = (int) nearbyint((image[i][j].rgbtRed + image[i][j+1].rgbtRed +image[i-1][j].rgbtRed +image[i-1][j+1].rgbtRed +image[i][j-1].rgbtRed +image[i-1][j-1].rgbtRed) / 6);
                int avgGreen = (int) nearbyint((image[i][j].rgbtGreen + image[i][j+1].rgbtGreen +image[i-1][j].rgbtGreen +image[i-1][j+1].rgbtGreen +image[i][j-1].rgbtGreen +image[i-1][j-1].rgbtGreen) / 6);
                int avgBlue = (int) nearbyint((image[i][j].rgbtBlue + image[i][j+1].rgbtBlue +image[i-1][j].rgbtBlue +image[i-1][j+1].rgbtBlue +image[i][j-1].rgbtBlue +image[i-1][j-1].rgbtBlue) / 6);

                placeholderImg[i][j].rgbtRed = avgRed;
                placeholderImg[i][j].rgbtGreen = avgGreen;
                placeholderImg[i][j].rgbtBlue = avgBlue;
                continue;
            }
            // EDGE CASE LEFT
            else if ((j == 0) && (!(i == 0 || i == width - 1)))
            {
                int avgRed = (int) nearbyint((image[i][j].rgbtRed + image[i][j+1].rgbtRed +image[i-1][j].rgbtRed +image[i-1][j+1].rgbtRed +image[i+1][j].rgbtRed +image[i+1][j+1].rgbtRed) / 6);
                int avgGreen = (int) nearbyint((image[i][j].rgbtGreen + image[i][j+1].rgbtGreen +image[i-1][j].rgbtGreen +image[i-1][j+1].rgbtGreen +image[i+1][j].rgbtGreen +image[i+1][j+1].rgbtGreen) / 6);
                int avgBlue = (int) nearbyint((image[i][j].rgbtBlue + image[i][j+1].rgbtBlue +image[i-1][j].rgbtBlue +image[i-1][j+1].rgbtBlue +image[i+1][j].rgbtBlue +image[i+1][j+1].rgbtBlue) / 6);

                placeholderImg[i][j].rgbtRed = avgRed;
                placeholderImg[i][j].rgbtGreen = avgGreen;
                placeholderImg[i][j].rgbtBlue = avgBlue;
                continue;
            }
            // EDGE CASE RIGHT
            else if ((j == height - 1) && (!(i == 0 || i == width - 1)))
            {
                int avgRed = (int) nearbyint((image[i][j].rgbtRed + image[i][j-1].rgbtRed +image[i-1][j].rgbtRed +image[i-1][j-1].rgbtRed +image[i+1][j-1].rgbtRed +image[i+1][j].rgbtRed) / 6);
                int avgGreen = (int) nearbyint((image[i][j].rgbtGreen + image[i][j-1].rgbtGreen +image[i-1][j].rgbtGreen +image[i-1][j-1].rgbtGreen +image[i+1][j-1].rgbtGreen +image[i+1][j].rgbtGreen) / 6);
                int avgBlue = (int) nearbyint((image[i][j].rgbtBlue + image[i][j-1].rgbtBlue +image[i-1][j].rgbtBlue +image[i-1][j-1].rgbtBlue +image[i+1][j-1].rgbtBlue +image[i+1][j].rgbtBlue) / 6);

                placeholderImg[i][j].rgbtRed = avgRed;
                placeholderImg[i][j].rgbtGreen = avgGreen;
                placeholderImg[i][j].rgbtBlue = avgBlue;
                continue;
            }

            // NORMAL CASE
            else //if (((j > 0) && (j < height -1)) && ((i > 0) && (i < height -1)))
            {
                int avgRed = (int) nearbyint((image[i-1][j-1].rgbtRed + image[i-1][j].rgbtRed +image[i-1][j+1].rgbtRed + image[i][j-1].rgbtRed + image[i][j].rgbtRed + image[i][j+1].rgbtRed + image[i+1][j-1].rgbtRed + image[i+1][j].rgbtRed + image[i+1][j+1].rgbtRed) / 9);
                int avgGreen = (int) nearbyint((image[i-1][j-1].rgbtGreen + image[i-1][j].rgbtGreen +image[i-1][j+1].rgbtGreen + image[i][j-1].rgbtGreen + image[i][j].rgbtGreen + image[i][j+1].rgbtGreen + image[i+1][j-1].rgbtGreen + image[i+1][j].rgbtGreen + image[i+1][j+1].rgbtGreen) / 9);
                int avgBlue = (int) nearbyint((image[i-1][j-1].rgbtBlue + image[i-1][j].rgbtBlue +image[i-1][j+1].rgbtBlue + image[i][j-1].rgbtBlue + image[i][j].rgbtBlue + image[i][j+1].rgbtBlue + image[i+1][j-1].rgbtBlue + image[i+1][j].rgbtBlue + image[i+1][j+1].rgbtBlue) / 9);

                placeholderImg[i][j].rgbtRed = avgRed;
                placeholderImg[i][j].rgbtGreen = avgGreen;
                placeholderImg[i][j].rgbtBlue = avgBlue;
                continue;
            }
        }
    }

    for (int x = 0; x < height - 1; x ++)
    {
        for (int y = 0; y < width - 1; y++)
        {
            image[x][y] = placeholderImg[x][y];
        }
    }
    return;
}