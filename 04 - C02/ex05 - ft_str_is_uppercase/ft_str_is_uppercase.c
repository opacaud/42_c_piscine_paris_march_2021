/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 07:06:46 by opacaud           #+#    #+#             */
/*   Updated: 2021/03/16 07:21:34 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_str_is_uppercase(char *str)
{
	int upper;
	int i;

	upper = 1;
	i = 0;
	while (str[i])
	{
		if (str[i] < 65 || str[i] > 90)
			upper = 0;
		i++;
	}
	return (upper);
}
