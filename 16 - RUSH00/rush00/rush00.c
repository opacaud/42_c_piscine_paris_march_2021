/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 10:23:53 by abensett          #+#    #+#             */
/*   Updated: 2021/03/14 15:13:48 by opacaud          ###   ########.fr       */
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
			ft_putchar('o');
		else if (i != x)
			ft_putchar('-');
		else
			ft_putchar('o');
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
			ft_putchar('o');
		else if (i != x)
			ft_putchar('-');
		else
			ft_putchar('o');
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
			ft_putchar('|');
		else if (i != x)
			ft_putchar(' ');
		else
			ft_putchar('|');
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

void	rush00(int x, int y)
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
