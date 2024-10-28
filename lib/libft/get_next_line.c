/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhtoo-h <juhtoo-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:32:43 by juhtoo-h          #+#    #+#             */
/*   Updated: 2024/10/01 11:45:27 by juhtoo-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_modify(char *buffer, char *new)
{
	char	*tmp;

	tmp = ft_strjoin(buffer, new);
	free(buffer);
	free(new);
	return (tmp);
}

static char	*ft_get_line(char *line_buffer)
{
	int		i;
	int		len;
	char	*line;

	if (line_buffer == NULL)
		return (NULL);
	len = ft_strlen(line_buffer);
	i = 0;
	while (line_buffer[i] != '\n' && line_buffer[i] != '\0')
		i++;
	while (i < len)
	{
		i++;
		line_buffer[i] = '\0';
	}
	line = ft_strdup(line_buffer);
	return (line);
}

static char	*ft_get_leftc(char *line_buffer)
{
	int		i;
	int		len;
	char	*left_c;

	if (line_buffer == NULL)
		return (NULL);
	len = ft_strlen(line_buffer);
	i = 0;
	while (line_buffer[i] != '\n' && line_buffer[i] != '\0')
		i++;
	left_c = ft_substr(line_buffer, i + 1, len - i);
	return (left_c);
}

static char	*ft_fill_line_buffer(int fd, char *buffer)
{
	char	*new;
	int		byte_read;

	byte_read = 1;
	while (byte_read > 0)
	{
		new = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		byte_read = read(fd, new, BUFFER_SIZE);
		if (byte_read == 0)
		{
			free(new);
			return (buffer);
		}
		if (byte_read == -1)
		{
			free(new);
			return (NULL);
		}
		new[byte_read] = '\0';
		buffer = ft_modify(buffer, new);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*left_c;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!ft_strchr(buffer, '\n'))
		buffer = ft_fill_line_buffer(fd, buffer);
	left_c = ft_get_leftc(buffer);
	line = ft_get_line(buffer);
	free(buffer);
	buffer = ft_strdup(left_c);
	free(left_c);
	return (line);
}
