#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


typedef uint8_t BYTE;


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

    char buffer[513];

    while (fread(buffer, 1, 512, forensic_img) == 512)
    {
        if (strcmp(buffer[0],"0xff") && strcmp(buffer[1], "0xd8") && strcmp(buffer[2], "0xff") && strcmp((buffer[3] & )))
    }

}