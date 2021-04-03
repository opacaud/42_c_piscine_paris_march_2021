/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 07:17:24 by opacaud           #+#    #+#             */
/*   Updated: 2021/03/25 11:56:09 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int	*tab;
	int	j;

	j = 0;
	if (min >= max)
		return (0);
	tab = (int *)malloc(sizeof(int) * (max - min));
	if (tab == 0)
		return (0);
	while (min < max)
	{
		tab[j] = min;
		j++;
		min++;
	}
	return (tab);
}
