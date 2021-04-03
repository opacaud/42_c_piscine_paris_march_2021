/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 16:27:10 by opacaud           #+#    #+#             */
/*   Updated: 2021/03/23 09:54:23 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *str)
{
	int counter;

	counter = 0;
	while (str[counter])
		counter++;
	return (counter);
}

int		ft_check_base(char *base)
{
	int i;
	int j;
	int abort;

	abort = 0;
	i = 0;
	if (base == NULL || ft_strlen(base) < 2)
		abort = 1;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' ||
				base[i] == '\n' || base[i] == '\t' ||
				base[i] == '\v' || base[i] == ' ' ||
				base[i] == '\r' || base[i] == '\f')
			abort = 1;
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				abort = 1;
			j++;
		}
		i++;
	}
	return (abort);
}

int		ft_index(char c, char *base)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int		ft_spaces(char c)
{
	int spaces;

	spaces = 0;
	if (c == ' ' || c == '\n' || c == '\t' || c == '\v'
			|| c == '\f' || c == '\r')
		spaces = 1;
	return (spaces);
}

int		ft_atoi_base(char *str, char *base)
{
	int result;
	int i;
	int signe;

	result = 0;
	i = 0;
	signe = 1;
	if (ft_check_base(base) == 0)
	{
		while (ft_spaces(str[i]) == 1)
			i++;
		while (str[i] == '+' || str[i] == '-')
		{
			if (str[i] == '-')
				signe *= -1;
			i++;
		}
		while (str[i] && ft_index(str[i], base) > -1)
		{
			result = result * ft_strlen(base) + ft_index(str[i], base);
			i++;
		}
		return (result * signe);
	}
	return (0);
}
