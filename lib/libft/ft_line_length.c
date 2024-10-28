/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_length.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhtoo-h <juhtoo-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:17:14 by juhtoo-h          #+#    #+#             */
/*   Updated: 2024/10/07 14:17:34 by juhtoo-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_line_length(int fd)
{
	char	buffer[1];
	int		len;
	int		byte;

	buffer[0] = '\0';
	len = 0;
	byte = 1;
	while (byte == 1 && buffer[0] != '\n')
	{
		byte = read(fd, buffer, 1);
		len++;
	}
	return (len);
}
