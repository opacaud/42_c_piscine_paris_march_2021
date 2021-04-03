/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wtsr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 07:06:35 by opacaud           #+#    #+#             */
/*   Updated: 2021/04/01 08:00:28 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>


#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		is_space(char c)
{
	if (c == ' ' || c == '\f' || c == '\t' || c == '\n' || c == '\r' || c == '\v')
		return (1);
	return (0);
}

void	ft_putstr_i(char *str, int i)
{
	while (str[i] != '\0' && is_space(str[i]) == 0)
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_rev_wstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	while (i > 0)
	{
		while (i >= 0 && is_space(str[i]) == 0)
			i--;
		i++;
		if (i >= 0)
			ft_putstr_i(str, i);
		if (i != 0)
			write(1, " ", 1);
		i--;
		while (i >= 0 && is_space(str[i]))
			i--;
	}
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	ft_rev_wstr(argv[1]);
	write(1, "\n", 1);
	return (0);
}
