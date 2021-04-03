/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 16:55:23 by opacaud           #+#    #+#             */
/*   Updated: 2021/03/18 10:27:13 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	int				difference;

	i = 0;
	difference = 0;
	while (difference == 0 && i < n)
	{
		difference = s1[i] - s2[i];
		i++;
		if ((s1[i] == 0) && (s2[i] == 0))
			break ;
	}
	return (difference);
}
