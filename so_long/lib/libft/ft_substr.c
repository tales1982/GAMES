/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlima-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:27:29 by tlima-de          #+#    #+#             */
/*   Updated: 2024/02/26 19:41:39 by tlima-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	ft_min(size_t start, size_t len)
{
	if (start < len)
		return (start);
	return (len);
}

static char	*empty_string(void)
{
	char	*result;

	result = malloc(1);
	if (result)
		result[0] = 0;
	return (result);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*str;

	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		str = empty_string();
		if (!str)
			return (NULL);
		return (str);
	}
	s_len -= (size_t)start;
	if (len > s_len)
		len = s_len;
	len = ft_min(s_len, len);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}
