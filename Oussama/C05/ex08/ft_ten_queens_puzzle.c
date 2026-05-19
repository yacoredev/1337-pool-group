/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oussama <oussama@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 10:26:07 by oussama           #+#    #+#             */
/*   Updated: 2026/05/19 10:04:39 by oussama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	print_board(int *board)
{
	char	c;
	int		i;

	i = 0;
	while (i < 10)
	{
		c = board[i] + '0';
		write (1, &c, 1);
		i++;
	}
	write (1, "\n", 1);
}

int	is_safe(int *board, int row, int col)
{
	int		i;

	i = 0;
	while (i < col)
	{
		if (board[i] == row)
			return (0);
		if (board[i] - row == col - i || row - board[i] == col - i)
			return (0);
		i++;
	}
	return (1);
}

int	solve_queens(int *board, int col)
{
	int		row;
	int		count;

	if (col == 10)
	{
		print_board(board);
		return (1);
	}
	row = 0;
	count = 0;
	while (row < 10)
	{
		if (is_safe(board, row, col))
		{
			board[col] = row;
			count = count + solve_queens(board, col + 1);
		}
		row++;
	}
	return (count);
}

int	ft_ten_queens_puzzle(void)
{
	int	board[10];

	return (solve_queens(board, 0));
}

int	main(void)
{
	printf("%d\n", ft_ten_queens_puzzle());
	return (0);
}
