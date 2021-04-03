/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_exam_last_day.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 08:56:55 by opacaud           #+#    #+#             */
/*   Updated: 2021/04/01 10:19:01 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>


#include <stdio.h>



int		get_size(int nbr)
{
	int size;

	size = 0;
	if (nbr == -2147483648)
		return(11);
	if (nbr == 0)
		return(1);
	if (nbr < 0)
	{
		nbr = -nbr;
		size++;
	}
	while (nbr > 0)
	{
		size++;
		nbr /= 10;
	}
	return (size);
}

char	*ft_itoa(int nbr)
{
	char *res;
	int size;

	size = get_size(nbr);
	res = malloc((sizeof(char)) * (size + 1));
	if (res == 0)
		return (0);
	if (nbr == -2147483648)
	{
		res = "-2147483648";
		return (res);
	}
	if (nbr == 0)
	{
		res[0] = '0';
		return (res);
	}
	if (nbr < 0)
	{
		res[0] = '-';
		nbr = -nbr;
	}
	res[size] = 0;
	while (nbr > 0)
	{
		size--;
		res[size] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (res);
}

int main(void)
{
	printf("%s\n", ft_itoa(-2147483648));
	printf("%d\n" , get_size(-2147483648));
}
