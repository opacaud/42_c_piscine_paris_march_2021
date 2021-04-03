/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 16:10:21 by opacaud           #+#    #+#             */
/*   Updated: 2021/03/19 15:25:15 by opacaud          ###   ########.fr       */
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
	int	i;
	int	j;
	int	abort;

	abort = 0;
	i = 0;
	if (base == NULL || ft_strlen(base) < 2)
		abort = 1;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
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

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	nbr_unsigned;
	unsigned int	base_size;
	int				check_base;

	check_base = ft_check_base(base);
	if (check_base == 0)
	{
		if (nbr < 0)
		{
			write(1, "-", 1);
			nbr_unsigned = (unsigned int)(-nbr);
		}
		else
			nbr_unsigned = (unsigned int)nbr;
		base_size = ft_strlen(base);
		if (nbr_unsigned >= base_size)
		{
			ft_putnbr_base((nbr_unsigned / base_size), base);
			ft_putnbr_base((nbr_unsigned % base_size), base);
		}
		else
			write(1, nbr_unsigned + base, 1);
	}
}
