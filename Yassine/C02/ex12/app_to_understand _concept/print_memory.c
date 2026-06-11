#include <stdio.h>

int main()
{
  char base[] = "0123456789abcdef";

  char str[] = "Bonjour les aminches\t\n\tc\7 est fou\t"
            "tout\tce qu on peut faire avec\t\t\n"
            "print_memory\n\n\n\tlol.lol\n ";

  void *add = str;
  long bytes_of_addr;
  unsigned char *ptr_to_addr;
  unsigned char *bytes_of_elm = (unsigned char *)add;

  if (!sizeof(str))
  {
    return (0);
  }

  int jump_line = 0;
  // Print the address of each line in array
  for (; jump_line < sizeof(str); jump_line+=16)
  {
    bytes_of_addr = (long)add + jump_line;
    ptr_to_addr = (unsigned char *)&bytes_of_addr;

    for (int i = sizeof(void *) - 1; i >= 0; i--) {
      printf("%c", base[(unsigned char)ptr_to_addr[i]/16]);
      printf("%c", base[(unsigned char)ptr_to_addr[i]%16]);
    }
    printf(": ");

    // Print the elements of array in hexa
    for (int i = jump_line; i < jump_line + 16; i++)
    {
      if (i < sizeof(str))
      {
        printf("%c", base[(unsigned char)bytes_of_elm[i]/16]);
        printf("%c", base[(unsigned char)bytes_of_elm[i]%16]);
      }
      else
      {
        printf("  ");
      }
      if (i%2)
        printf(" ");
    }

    // print the elements in ascii characters
    for (int i = jump_line; i < jump_line + 16 && i < sizeof(str); i++)
    {
      if (bytes_of_elm[i] >= ' ' && bytes_of_elm[i] <= '~')
        printf("%c", bytes_of_elm[i]);
      else
        printf(".");
    }
    printf("\n");
  }
}