/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlima-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 19:15:06 by tlima-de          #+#    #+#             */
/*   Updated: 2024/03/01 19:36:48 by tlima-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_negative_num(size_t *len, size_t *sig, int n)
{
	size_t	nbr;

	if (n < 0)
	{
		if (n == -2147483647 - 1)
			nbr = 1 + (size_t)2147483647;
		else
			nbr = -n;
		*len += 1;
		*sig = 1;
	}
	else
		nbr = n;
	return (nbr);
}

static size_t	ft_leng(int n)
{
	size_t	len;

	n /= 10;
	len = 1;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	size_t	len;
	size_t	sig;
	size_t	nbr;	
	char	*str;

	len = ft_leng(n);
	sig = 0;
	nbr = ft_negative_num(&len, &sig, n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (sig)
		*str = '-';
	str[len] = '\0';
	while (sig < len--)
	{
		str[len] = (char)(nbr % 10 + '0');
		nbr /= 10;
	}
	return (str);
}
