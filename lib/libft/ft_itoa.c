/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhtoo-h <juhtoo-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:36:58 by juhtoo-h          #+#    #+#             */
/*   Updated: 2024/12/19 09:14:04 by juhtoo-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	size_generator(long n)
{
	int	size;

	size = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		size++;
	}
	while (n > 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	int		i;
	int		size;
	long	num;
	char	*str;

	num = (long)n;
	size = size_generator(num);
	str = (char *)malloc(sizeof(char) * (size + 1));
	str[0] = '0';
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	i = 0;
	while (num > 0)
	{
		str[size - i - 1] = (num % 10) + '0';
		num = num / 10;
		i++;
	}
	str[size] = '\0';
	return (str);
}
