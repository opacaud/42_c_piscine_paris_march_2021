/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 11:18:47 by opacaud           #+#    #+#             */
/*   Updated: 2021/03/17 07:13:08 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_change_case(char *str)
{
	int i;

	i = 1;
	while (str[i])
	{
		if (str[i] > 96 && str[i] < 123)
		{
			if ((str[i - 1] < 65) || (str[i - 1] > 122))
				str[i] = str[i] - 32;
			else if (str[i - 1] > 90 && str[i - 1] < 97)
				str[i] = str[i] - 32;
		}
		if (str[i] > 64 && str[i] < 91)
		{
			if (str[i - 1] > 64 && str[i - 1] < 91)
				str[i] = str[i] + 32;
			else if (str[i - 1] > 96 && str[i - 1] < 123)
				str[i] = str[i] + 32;
			else if (str[i - 1] > 47 && str[i - 1] < 58)
				str[i] = str[i] + 32;
		}
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	char *str_good;

	if (str[0] > 96 && str[0] < 123)
		str[0] = str[0] - 32;
	str_good = ft_change_case(str);
	return (str_good);
}
