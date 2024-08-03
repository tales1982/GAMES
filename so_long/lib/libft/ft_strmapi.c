/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlima-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 15:40:26 by tlima-de          #+#    #+#             */
/*   Updated: 2024/03/02 16:01:10 by tlima-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	length;
	size_t	index;
	char	*str;

	length = ft_strlen(s);
	index = 0;
	str = (char *)malloc(sizeof(char) * (length + 1));
	if (!str)
		return (NULL);
	while (index < length)
	{
		str[index] = f(index, s[index]);
		index++;
	}
	str[length] = '\0';
	return (str);
}
