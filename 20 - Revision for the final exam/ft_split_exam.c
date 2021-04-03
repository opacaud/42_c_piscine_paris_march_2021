/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_exam_last_day.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 08:01:54 by opacaud           #+#    #+#             */
/*   Updated: 2021/04/01 08:22:30 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>


// #include <stdio.h>

int		is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\v' || c == '\n' || c == '\r' || c == '\f')
		return (1);
	return (0);
}

int		ft_words(char *str)
{
	int count;
	int i;
	
	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && is_space(str[i]))
			i++;
		if (str[i] && is_space(str[i]) == 0)
			count++;
		while (str[i] && is_space(str[i]) == 0)
			i++;
	}
	return (count);
}


int		ft_letters(char *str, int i)
{
	int count;

	count= 0;
	while (str[i] && is_space(str[i]) == 0)
	{
		count++;
		i++;
	}
	return (count);
}


char	**ft_split(char *str)
{
	char **tab;
	int words;
	int i;
	int j;
	int k;
	int letters;

	words = ft_words(str);
	tab = malloc((sizeof(char *)) * (words + 1));
	if (tab == 0)
		return (0);
	i = 0;
	j = 0;
	while (j < words)
	{
		while (str[i] && is_space(str[i]))
			i++;
		letters = ft_letters(str, i);
		tab[j] = malloc((sizeof(char)) * (letters + 1));
		if (tab[j] == 0)
			return (0);
		k = 0;
		while (str[i] && is_space(str[i]) == 0)
		{
			tab[j][k] = str[i];
			k++;
			i++;
		}
		tab[j][k] = 0;
		j++;
	}
	tab[j] = 0;

/*

	i = 0;
	while (i < words + 1)
	{
		printf("tab[%d] : %s\n", i, tab[i]);
		i++;
	}

*/

	return (tab);
}

int main(void)
{
//	printf("%d\n", ft_words("     hello ca va ? 	  lol \n"));
//	printf("%d\n", ft_letters("   hello ca va ?   lol \n", 3));
	char hello[] = "Bonjour comment ca va ?";
	ft_split(hello);
	return(0);
}
