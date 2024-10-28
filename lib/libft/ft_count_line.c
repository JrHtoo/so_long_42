/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhtoo-h <juhtoo-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:18:18 by juhtoo-h          #+#    #+#             */
/*   Updated: 2024/10/08 11:34:09 by juhtoo-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_line(int fd)
{
	int		count;
	char	*line;

	line = get_next_line(fd);
	count = 1;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		count++;
	}
	return (count);
}
