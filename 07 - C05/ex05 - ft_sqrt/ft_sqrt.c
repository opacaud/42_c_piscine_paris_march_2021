/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 07:14:47 by opacaud           #+#    #+#             */
/*   Updated: 2021/03/22 12:13:37 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_sqrt(int nb)
{
	unsigned int i;
	unsigned int nb_unsigned;

	if (nb < 1)
		return (0);
	if (nb == 1)
		return (1);
	i = 1;
	nb_unsigned = (unsigned int)nb;
	while (i * i <= nb_unsigned)
	{
		if (i * i == nb_unsigned)
			return (i);
		else
			i++;
	}
	return (0);
}
