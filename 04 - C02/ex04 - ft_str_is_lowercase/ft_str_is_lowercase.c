/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 07:06:46 by opacaud           #+#    #+#             */
/*   Updated: 2021/03/16 07:19:54 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_str_is_lowercase(char *str)
{
	int lower;
	int i;

	lower = 1;
	i = 0;
	while (str[i])
	{
		if (str[i] < 97 || str[i] > 122)
			lower = 0;
		i++;
	}
	return (lower);
}