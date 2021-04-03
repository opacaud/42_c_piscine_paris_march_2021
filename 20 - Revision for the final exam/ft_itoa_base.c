/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 10:19:09 by opacaud           #+#    #+#             */
/*   Updated: 2021/04/01 11:38:28 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		get_size(int nbr, int base)
{
	int size;

	size = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0 && base == 10)
	{
		size++;
	}
	if (nbr < 0)
		nbr = -nbr;
	while (nbr > 0)
	{
		size++;
		nbr /= base;
	}
	return (size);
}

char	*ft_itoa_base(int value, int base)
{
	char *res;
	int size;
	char *base_digits;

	base_digits = "0123456789ABCDEF";
	size = get_size(value, base);
	res = malloc((sizeof(char)) * (size + 1));
	if (res == 0)
		return (0);
	if (value == 0)
	{
		res[0] = base_digits[0];
		return (res);
	}
	if (value == -2147483648 && base == 10)
	{
		res = "-2147483648";
		return (res);
	}
	if (value < 0 && base == 10)
		res[0] = '-';
	if (value < 0)
		value = -value;
	res[size] = 0;
	while (value > 0)
	{
		size--;
		res[size] = base_digits[value % base];
		value /= base;
	}
	return (res);
}

int main(void)
{
	printf("%s\n", ft_itoa_base(-2147483648, 16));
	return (0);
}
