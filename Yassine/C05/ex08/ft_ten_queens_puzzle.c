/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaadi <ybaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 18:18:21 by ybaadi            #+#    #+#             */
/*   Updated: 2026/05/13 13:32:44 by ybaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
    Where is the backtracking happening?

    After recursive return,
    the loop continues trying other possibilities.
*/

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int is_same_diagonal(int o_row, int c_row, int o_clm, int c_clm)
{
  int deff_row;
  int deff_clm;
  
  deff_row = c_row - o_row;
  deff_clm = c_clm - o_clm;
  
  // If one of them is negative, the sec condition balances it
  if (deff_row == deff_clm || deff_row == -deff_clm)
  {
    return (1);
  }
  return (0);
}

void print_results(int *box, int size)
{
    int i;
    
    i = 0;
    while (i < size)
    {
      ft_putchar(box[i] + '0');
      i++;
    }
    ft_putchar('\n');
}

int is_place_valid(int clm, int *box, int row)
{
    int i;
    
    i = 0;
    /*
      nfso had condition li kykhli awal queen t7at f r0 c0.
      compare current place in all previous columns
    */
    while (i < clm)
    {
      /*
        check if place valid (row and diagonal)
        box[i]: previous rows
       */
      if ((box[i] == row) || (is_same_diagonal(box[i], row, i, clm)))
      {
        return (0);
      }
      i++;
    }
    return (1);
}

void ft_puzzle(int clm, int *box, int size, int *count)
{
  int row;

  // base case
  if (clm == size)
  {
    print_results(box, size);
    *count += 1;
    return;
  }

  /*
    loop for all rows in 'clm'
    each column: check all rows if safe place, otherwise backtrack
  */
  row = 0;
  while (row < size)
  {
    /*
      search of safe row in current column (level)
      In comparison of all previous columns
      otherwise move to the next row
    */
    if (is_place_valid(clm, box, row))
    {
      box[clm] = row;
      ft_puzzle(clm + 1, box, size, count);
    }
    row++;
  }
  return;
}

/*
  fach katprinti lina awal solution tl9ah ghadi trja3 l column (level) ma9abl akhir w 
  thbtha (queen) lrow li tab3 hta tl9a liha blasa (ila mal9atch lih blasa kat3awd 
  trja3 l column li 9bal w tbdal liha blasa hta tl9a blasa safe) wa haka hta 
  tl9a solution tanya tprintiha w t3awd trj3 bnafs tari9a hta nsaliw ga3 rows 
  dyal awal column
*/
int     ft_ten_queens_puzzle(void)
{
  int size = 10;
  int box[size];
  int count = 0;
  
  /*
    kanb9a ghadi 7ta nsali ga3 rows dyal awal colm,
    kanjarab all solutions possible for each row mno
  */
  ft_puzzle(0, box, size, &count);
  
  return (count);
}

/*
#include <stdio.h>
int main(void)
{
    printf("%d solutions found\n", ft_ten_queens_puzzle());
    
    return (0);
}
*/