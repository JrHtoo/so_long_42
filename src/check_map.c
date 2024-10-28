/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhtoo-h <juhtoo-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:01:16 by juhtoo-h          #+#    #+#             */
/*   Updated: 2024/10/18 09:09:47 by juhtoo-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	check_borders(t_data data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data.map.size.y)
	{
		if (ft_strlen(data.map.map[y]) != data.map.size.x)
			ft_print_error(&data, "Error...Map has to be a rectangular\n");
		x = 0;
		while (x < data.map.size.x - 1)
		{
			if (data.map.map[y][x] != '1' && data.map.map[y][x] != '0'
			&& data.map.map[y][x] != 'C' && data.map.map[y][x] != 'P'
			&& data.map.map[y][x] != 'E')
				ft_print_error(&data, "Only 1,0,E,P,C are allowed!\n");
			else if ((y == 0 || x == 0) && data.map.map[y][x] != '1')
				ft_print_error(&data, "The borders are not bordering\n");
			else if ((y == data.map.size.y - 1 || x == data.map.size.x - 2)
				&& data.map.map[y][x] != '1')
				ft_print_error(&data, "The borders are not bordering\n");
			x++;
		}
		y++;
	}
}

static void	check_contents(t_data data)
{
	int	i;
	int	player;
	int	exit;

	i = 0;
	player = 0;
	exit = 0;
	data.map.to_collect = 0;
	while (i < data.map.size.y)
	{
		player += ft_count_char(data.map.map[i], 'P');
		exit += ft_count_char(data.map.map[i], 'E');
		data.map.to_collect += ft_count_char(data.map.map[i], 'C');
		i++;
	}
	if (player != 1)
		ft_print_error(&data, "Error! There should be only one player\n");
	if (exit < 1)
		ft_print_error(&data,
			"Error! A proper map should contain at least one exit");
	if (data.map.to_collect < 1)
		ft_print_error(&data,
			"Error! There should be at least a thing to collect!\n");
}

static void	check_route(t_data *data)
{
	int		exit;
	char	**copy_map;

	data->player.position = ft_findpos(data, 'P');
	copy_map = ft_copy_map(*data);
	exit = ft_mapchr(copy_map, data->map.size, 'E');
	flood_fill(copy_map, data->map.size,
		data->player.position.x, data->player.position.y);
	if (ft_mapchr(copy_map, data->map.size, 'C') > 0)
	{
		ft_freemap(copy_map, data->map.size.y);
		ft_print_error(data, "The collection is out of route\n");
	}
	if ((exit == 1 && ft_mapchr(copy_map, data->map.size, 'E') != 0)
		|| (exit > 1 && ft_mapchr(copy_map, data->map.size, 'E') == exit))
	{
		ft_freemap(copy_map, data->map.size.y);
		ft_print_error(data, "The exit is out of reach\n");
	}
	ft_freemap(copy_map, data->map.size.y);
}

void	read_map(t_data *data, char *map_path)
{
	int		i;
	int		fd;
	char	*line;

	fd = open(map_path, O_RDONLY);
	data->map.map = ft_calloc(data->map.size.y + 1, sizeof(char *));
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		data->map.map[i] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	check_borders(*data);
	check_contents(*data);
	check_route(data);
	printf("%d %d\n", data->player.position.x, data->player.position.y);
}
