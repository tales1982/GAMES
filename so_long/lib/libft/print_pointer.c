/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tales <tales@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:55:48 by tlima-de          #+#    #+#             */
/*   Updated: 2024/06/01 11:28:28 by tales            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*string(unsigned long value, int *strlen)
{
	unsigned long	temp;
	char			*str;
	int				i;

	i = 0;
	temp = value;
	while (temp != 0)
	{
		temp = temp / 16;
		i++;
	}
	str = calloc(i + 1, sizeof(char));
	*strlen = i - 1;
	return (str);
}

int	printnil(unsigned long value)
{
	int	count;

	count = 0;
	if (value == 0)
		count += print_string("(nil)");
	return (count);
}

int	print_pointer(unsigned long value, int asc)
{
	int		count;
	char	*printout;
	int		*iptr;
	int		i;

	count = printnil(value);
	if (count != 0)
		return (count);
	iptr = &i;
	printout = string(value, iptr);
	if (!printout)
		return (0);
	while (value != 0 && i-- >= 0)
	{
		if ((value % 16) < 10)
			printout[i + 1] = (value % 16) + '0';
		else
			printout[i + 1] = (value % 16) + asc;
		value /= 16;
	}
	count = print_string("0x");
	count += ft_strlen(printout);
	ft_putstr_fd(printout, 1);
	free(printout);
	return (count);
}
