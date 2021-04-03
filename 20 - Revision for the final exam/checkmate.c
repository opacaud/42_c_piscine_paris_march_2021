/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chessmate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 14:56:10 by opacaud           #+#    #+#             */
/*   Updated: 2021/03/31 15:57:21 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>


#include <stdio.h>


void    ft_putstr(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

int    chessmate(char **tab, int nb)
{
	int king_i;
	int king_j;
	int i;
	int j;
	int success;

	i = 0;
	success = 0;
	while (i < nb)
	{
		j = 0;
		while (j < nb)
		{
			if (tab[i][j] == 'K')
			{
				king_i = i;
				king_j = j;
			}
			j++;
		}
		i++;
	}
	j = 0;
	while (j < nb)
	{
		if (tab[king_i][j] == 'R' || tab[king_i][j] == 'Q')
			success = 1;
		j++;
	}
	i = 0;
	while (i < nb)
	{
		if (tab[i][king_j] == 'R' || tab[i][king_j] == 'Q')
			success = 1;
		i++;
	}
	if (king_i - 1 < nb && king_j - 1 < nb && king_i + 1 < nb && king_j + 1 < nb)
	{
		if (tab[king_i + 1][king_j - 1] == 'P' || tab[king_i + 1][king_j + 1] == 'P')
			success = 1;
	}
	i = 1;
	while (king_i - i < nb && king_j - j < nb && king_i + i < nb && king_j + j < nb)
	{
		j = 1;
		while (king_i - i < nb && king_j - j < nb && king_i + i < nb && king_j + j < nb)
		{
			if (tab[king_i - i][king_j - j] == 'B' || tab[king_i - i][king_j - j] == 'Q'
					|| tab[king_i - i][king_j + j] == 'B' || tab[king_i - i][king_j + j] == 'Q'
					|| tab[king_i + i][king_j - j] == 'B' || tab[king_i + i][king_j - j] == 'Q'
					|| tab[king_i + i][king_j + j] == 'B' || tab[king_i + i][king_j + j] == 'Q')
				success = 1;
			i++;
			j++;
		} 
		i++;
	}
	if (success == 1)
	{
		ft_putstr("Success");
		write(1,"\n", 1);
		return (0);
	}
	else
	{
		ft_putstr("Fail");
		write(1,"\n", 1);
		return(0);
	}
}

int     ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int main(int argc, char **argv)
{
	int i;
	int j;
	int k;
	char **tab_argv;

	i = 0;
	if (argc < 3)
	{
		write(1, "\n", 1);
		return (1);
	}
	while (i < argc)
	{
		if (argv[i] == 0)
		{
			write(1, "\n", 1);
			return (1);
		}
		i++;
	}
	tab_argv = malloc((sizeof(char *) * argc));
	if (tab_argv == 0)
		return (0);
	j = 0;
	while (j < argc - 1)
	{
		tab_argv[j] = malloc((sizeof(char)) * argc);
		if (tab_argv[j] == 0)
			return (0);
		k = 0;
		while (k < argc - 1)
		{
			tab_argv[j][k] = argv[j + 1][k];
			k++;
		}
		tab_argv[j][k] = 0;
		j++;
	}
	tab_argv[j] = 0;

	i = 0;
	/*   while (tab_argv[i])
		 {
		 printf("tab[%d] : %s\n", i, tab_argv[i]);
		 i++;
		 }*/
	chessmate(tab_argv, (argc - 1));
	return(0);
}
