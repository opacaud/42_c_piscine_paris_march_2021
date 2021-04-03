/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 07:18:23 by opacaud           #+#    #+#             */
/*   Updated: 2021/03/25 11:58:29 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int size;
	int i;
	int j;

	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	size = max - min;
	*range = malloc(sizeof(int) * size);
	if (*range == 0)
		return (-1);
	i = min;
	j = 0;
	while (i < max)
	{
		(*range)[j] = i;
		j++;
		i++;
	}
	return (max - min);
}
