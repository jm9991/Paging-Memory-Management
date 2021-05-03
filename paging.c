#include <stdio.h>
#include <stdlib.h>

#define PAGE_NUMBER_MASK 1048575
#define OFFSET_MASK 4095
#define PAGES 8
#define OFFSET_BITS 12
#define PAGE_SIZE 4096
#define BUFFER_SIZE 10

char buff[BUFFER_SIZE];

int page_number;
int frame_number;
int virtual_address;
int physical_address;
int offset;

int page_table[PAGES] = {6,4,3,7,0,1,2,5};

int main(int argc, char *argv[]) {

    FILE *fptr = fopen(argv[1], "r");

    while(fgets(buff, BUFFER_SIZE, fptr) != NULL)
    {
       virtual_address = atoi(buff);
       page_number = (virtual_address >> OFFSET_BITS) &  PAGE_NUMBER_MASK;
       offset = virtual_address & OFFSET_MASK;
       frame_number = page_table[page_number];
       physical_address = (frame_number << OFFSET_BITS) | offset;

       printf("Virtual addr is %d : Page# = %d & Offset = %d Physical addr = %d \n",virtual_address,page_number, offset, physical_address); 
    }
fclose(fptr);
}
