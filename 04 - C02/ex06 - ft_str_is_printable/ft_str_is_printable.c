/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 07:06:46 by opacaud           #+#    #+#             */
/*   Updated: 2021/03/16 07:22:40 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_str_is_printable(char *str)
{
	int printable;
	int i;

	printable = 1;
	i = 0;
	while (str[i])
	{
		if (str[i] < 32 || str[i] == 127)
			printable = 0;
		i++;
	}
	return (printable);
}
