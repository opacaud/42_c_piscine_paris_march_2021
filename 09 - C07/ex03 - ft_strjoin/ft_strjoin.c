/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 14:38:25 by opacaud           #+#    #+#             */
/*   Updated: 2021/03/26 17:56:51 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int		ft_count_car(char **strs, int size)
{
	int	caracteres;
	int i;
	int j;

	caracteres = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			caracteres++;
			j++;
		}
		i++;
	}
	return (caracteres);
}

char	*ft_copy(char **strs, char *dest, char *sep, int size)
{
	int i;
	int j;
	int k;
	int but;

	i = -1;
	but = 0;
	while (++i < size)
	{
		j = 0;
		while (j < ft_strlen(strs[i]))
		{
			dest[but++] = strs[i][j];
			j++;
		}
		k = 0;
		if (i < size - 1)
		{
			while (k < ft_strlen(sep))
				dest[but++] = sep[k++];
		}
	}
	dest[but] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	int		caracteres;

	if (size == 0)
	{
		str = (char *)malloc(sizeof(char));
		if (str != 0)
			*str = '\0';
		return (str);
	}
	caracteres = ft_count_car(strs, size) + ((size - 1) * ft_strlen(sep));
	str = (char *)malloc(sizeof(char) * (caracteres + 1));
	if (str == 0)
		return (str);
	str = ft_copy(strs, str, sep, size);
	return (str);
}
