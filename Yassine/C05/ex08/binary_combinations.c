#include <stdio.h>

void print_comb(int *comb, int size)
{
  for(int i = 0; i < size; i++)
  {
    printf("%d", comb[i]);
  }
  printf("\n");
}

void generate_comb(int *comb, int idx, int size, int *ctr)
{
  if (idx == size)
  {
    print_comb(comb, size);
    *ctr += 1;
    return;
  }

  comb[idx] = 0;
  generate_comb(comb, idx + 1, size, ctr);
  comb[idx] = 1;
  generate_comb(comb, idx + 1, size, ctr);
  
  return;
}

int binary_comb()
{
  int comb[3];
  int size = 3;
  int count = 0;
  
  generate_comb(comb, 0, size, &count);
  
  return(count);
}

int main()
{
  printf("%d combinations found\n", binary_comb());
  return(0);
}