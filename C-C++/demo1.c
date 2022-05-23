#include <avr/io.h>
#include "uart.h"


void writestr(char *Str1, char *Str2, char *Str3, char *Str4) {

int i = 0, j = 0, k = 0, n = 0;

while(Str1 != '\0') {
uart_writechar(Str1[i]);

i++;
}
while(Str2 != '\0'){
uart_writechar(Str2[j]);

j++;
}
while(Str3 != '\0'){
uart_writechar(Str3[k]);

k++;
}
while(Str4 != '\0'){
uart_writechar(Str4[n]);

n++;
}
}

// Function to convert char string to integer
int convert1(char Str1[])
{
int i, n;

n = 0;

for(i=0; Str1[i] >= '0' && Str1[i] <= '9'; i++)

n = 10 * n + (Str1[i] - '0');

return n;
}

int main(int argc, char const *argv[])
{

uart_init();


char *Str1[] = {"Hello World from Atmega328 \n\r SER486 -- Homework Assignment 1 \n\r Stephen Hamilton \n\r"};

int charStringSize = convert1(Str1); // THIS SHOULD HAVE WORKED!!!!!!!!!!!!!!

char *Str2[] = {"char size (bits) = %d (bits) \n\r", charStringSize}; // Trying to figure out how to utilize above function

int intStringSize = (int)sizeof(*Str1);

char *Str3[] = {"int size (bits) = %d (bits) \n\r", intStringSize};

int longStringSize = (long)sizeof(*Str1);

char *Str4[] = {"long size (bits) = %l (bits) \n\r", longStringSize};

writestr(*Str1, *Str2, *Str3, *Str4);


return 0;

}
