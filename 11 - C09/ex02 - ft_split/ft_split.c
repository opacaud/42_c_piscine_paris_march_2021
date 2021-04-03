/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 08:18:38 by opacaud           #+#    #+#             */
/*   Updated: 2021/03/29 17:36:17 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		is_charset(char c, char *charset)
{
	int i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int		ft_count_lines(char *str, char *charset)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] != '\0' && is_charset(str[i], charset))
			i++;
		if (str[i] != '\0' && is_charset(str[i], charset) == 0)
			count++;
		while (str[i] != '\0' && is_charset(str[i], charset) == 0)
			i++;
	}
	return (count);
}

int		ft_str_s(char *str, char *charset, int j)
{
	int str_size;

	str_size = 0;
	while (str[j] != '\0' && (is_charset(str[j], charset) == 0))
	{
		str_size++;
		j++;
	}
	return (str_size);
}

char	**ft_split(char *str, char *charset)
{
	char	**tab;
	int		lines;
	int		i;
	int		j;
	int		k;

	lines = ft_count_lines(str, charset);
	if (!(tab = (char **)malloc((sizeof(char *)) * (lines + 1))))
		return (0);
	i = 0;
	j = 0;
	while (i < lines)
	{
		while (str[j] != '\0' && is_charset(str[j], charset))
			j++;
		if (!(tab[i] = malloc(sizeof(char) * (ft_str_s(str, charset, j) + 1))))
			return (0);
		k = 0;
		while (str[j] != '\0' && is_charset(str[j], charset) == 0)
			tab[i][k++] = str[j++];
		tab[i][k] = '\0';
		i++;
	}
	tab[i] = 0;
	return (tab);
}
