/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:41:26 by opacaud           #+#    #+#             */
/*   Updated: 2021/03/26 16:20:27 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		ft_strlen(char *s);
int		ft_check_base(char *base);

int		ft_index(char *base, char c)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int		ft_atoi_base(char *nbr, char *base_from)
{
	int			signe;
	int			i;
	long int	nbr_dec;

	signe = 1;
	i = 0;
	nbr_dec = 0;
	while (nbr[i] == ' ' || nbr[i] == '\n' || nbr[i] == '\t'
			|| nbr[i] == '\v' || nbr[i] == '\f' || nbr[i] == '\r')
		i++;
	while (nbr[i] == '+' || nbr[i] == '-')
	{
		if (nbr[i] == '-')
			signe *= -1;
		i++;
	}
	while (nbr[i] && ft_index(base_from, nbr[i]) > -1)
	{
		nbr_dec = nbr_dec * ft_strlen(base_from) + ft_index(base_from, nbr[i]);
		i++;
	}
	nbr_dec = nbr_dec * signe;
	return (nbr_dec);
}

int		ft_new_nbr_size(long int nb, long int base_size)
{
	int			i;
	long int	nombre;

	i = 1;
	if (nb < 0)
	{
		nombre = (long int)(-nb);
		i++;
	}
	else
		nombre = (long int)(nb);
	while (nombre >= base_size)
	{
		nombre /= base_size;
		i++;
	}
	return (i);
}

char	*ft_itoa_base(long int nb, char *base, char *s)
{
	long int		base_size;
	long int		nbr_size;
	long int		nombre;

	base_size = ft_strlen(base);
	nbr_size = ft_new_nbr_size(nb, base_size);
	if (!(s = (char *)malloc((sizeof(char)) * (nbr_size + 1))))
		return (0);
	s[nbr_size--] = '\0';
	if (nb < 0)
	{
		nombre = (long int)(-nb);
		s[0] = '-';
	}
	else
		nombre = (long int)(nb);
	if (nombre == 0)
		s[0] = base[0];
	while (nombre > 0)
	{
		s[nbr_size] = base[nombre % base_size];
		nombre /= base_size;
		nbr_size--;
	}
	return (s);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char			*s;
	long int		nbr_dec;

	s = NULL;
	nbr_dec = 0;
	if (ft_check_base(base_from) && ft_check_base(base_to))
	{
		nbr_dec = ft_atoi_base(nbr, base_from);
		s = ft_itoa_base(nbr_dec, base_to, s);
		return (s);
	}
	else
		return (NULL);
}
