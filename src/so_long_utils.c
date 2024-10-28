/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhtoo-h <juhtoo-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:44:35 by juhtoo-h          #+#    #+#             */
/*   Updated: 2024/10/18 09:06:47 by juhtoo-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_pos	ft_findpos(t_data *data, char c)
{
	t_pos	pos;

	pos.x = 0;
	while (pos.x < data->map.size.x)
	{
		pos.y = 0;
		while (pos.y < data->map.size.y)
		{
			if (data->map.map[pos.y][pos.x] == c)
				return (pos);
			pos.y++;
		}
		pos.x++;
	}
	return (pos);
}

void	ft_freemap(char **map, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	ft_mapchr(char **map, t_pos size, char c)
{
	int	x;
	int	y;
	int	count;

	x = 0;
	count = 0;
	while (x < size.x)
	{
		y = 0;
		while (y < size.y)
		{
			if (map[y][x] == c)
				count++;
			y++;
		}
		x++;
	}
	return (count);
}

void	flood_fill(char **map, t_pos size, int row, int col)
{
	if (row < 0 || col < 0 || row >= size.y || col >= size.x)
		return ;
	if (map[row][col] == '1' || map[row][col] == '5')
		return ;
	map[row][col] = '5';
	flood_fill(map, size, row - 1, col);
	flood_fill(map, size, row + 1, col);
	flood_fill(map, size, row, col - 1);
	flood_fill(map, size, row, col + 1);
}

char	**ft_copy_map(t_data data)
{
	int		i;
	char	**copy_map;

	copy_map = ft_calloc(data.map.size.y + 1, sizeof(char *));
	i = 0;
	while (data.map.map[i])
	{
		copy_map[i] = ft_strdup(data.map.map[i]);
		i++;
	}
	return (copy_map);
}
