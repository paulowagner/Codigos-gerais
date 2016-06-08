#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
  char *str1 = "010w";
  char *str2 = "0x11111111";

/* Converter hexadecimal para long */
  printf ("%ld\n", strtol (str1, NULL, 0));

/* Converter binário para long */
  printf ("%ld\n", strtol (str2, NULL, 2));

  return 0;
} 