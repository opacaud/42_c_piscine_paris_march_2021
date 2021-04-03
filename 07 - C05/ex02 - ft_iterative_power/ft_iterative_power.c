/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 12:25:00 by opacaud           #+#    #+#             */
/*   Updated: 2021/03/22 13:41:12 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_iterative_power(int nb, int power)
{
	int i;
	int res;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	res = nb;
	i = 1;
	while (i < power)
	{
		res = res * nb;
		i++;
	}
	return (res);
}
