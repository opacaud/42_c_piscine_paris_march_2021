/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 15:23:42 by abensett          #+#    #+#             */
/*   Updated: 2021/03/14 15:19:03 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_print_first_line(int x)
{
	int i;

	i = 1;
	while (i <= x)
	{
		if (i == 1)
			ft_putchar('A');
		else if (i != x)
			ft_putchar('B');
		else
			ft_putchar('C');
		i++;
	}
}

void	ft_print_last_line(int x)
{
	int i;

	i = 1;
	while (i <= x)
	{
		if (i == 1)
			ft_putchar('C');
		else if (i != x)
			ft_putchar('B');
		else
			ft_putchar('A');
		i++;
	}
}

void	ft_print_line(int x)
{
	int i;

	i = 1;
	while (i <= x)
	{
		if (i == 1)
			ft_putchar('B');
		else if (i != x)
			ft_putchar(' ');
		else
			ft_putchar('B');
		i++;
	}
}

void	ft_exception(int x, int y)
{
	if (x <= 0)
	{
		write(1, "X doit être strictement supérieur à 0.", 41);
		write(1, "\n", 1);
	}
	if (y <= 0)
	{
		write(1, "Y doit être strictement supérieur à 0.", 41);
		write(1, "\n", 1);
	}
	return ;
}

void	rush04(int x, int y)
{
	int i;

	i = 1;
	ft_exception(x, y);
	while (i <= y)
	{
		if (i == 1)
			ft_print_first_line(x);
		else if (i != y)
			ft_print_line(x);
		else
			ft_print_last_line(x);
		ft_putchar('\n');
		i++;
	}
}
