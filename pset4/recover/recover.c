#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


typedef uint8_t BYTE;

#define BLOCK_SIZE 512

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE \n");
        return 1;
    }

    FILE *forensic_img = fopen(argv[1], "r");

    if (forensic_img == NULL)
    {
        printf("The forensic image cannot be opened\n");
        return 1;
    }

    BYTE buffer[BLOCK_SIZE];
    char filename[8];
    int count = 0;
    int found = 0;
    FILE *img;
    while (fread(buffer, 1, BLOCK_SIZE, forensic_img) == BLOCK_SIZE)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (!found)
            {
                sprintf(filename, "%03i.jpg", count);
                img = fopen(filename, "w");
                fwrite(buffer, BLOCK_SIZE, 1, img);
                found = 1;
            }
            else
            {
                fclose(img);
                sprintf(filename, "%03i.jpg", count);
                img = fopen(filename, "w");
                fwrite(buffer, BLOCK_SIZE, 1, img);
            }
            count++;
        }
        else
        {
            if (found)
            {
                fwrite(buffer, BLOCK_SIZE, 1, img);
            }
        }
    }

    fclose(img);
    fclose(forensic_img);
}