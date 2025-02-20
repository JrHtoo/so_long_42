/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhtoo-h <juhtoo-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:05:10 by juhtoo-h          #+#    #+#             */
/*   Updated: 2025/02/19 14:52:04 by juhtoo-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	ft_window_size(t_data *data, char *map_path)
{
	int	fd;
	int	n;

	n = ft_strlen(map_path) - 1;
	fd = open(map_path, O_RDONLY);
	if (fd < 0 || (map_path[n] != 'r' && map_path[n - 1] != 'e'
			&& map_path[n - 2] != 'b' && map_path[n - 3] != '.'))
	{
		perror("Error! Invalid map_path/map");
		exit(EXIT_FAILURE);
	}
	data->map.size.x = ft_line_length(fd);
	data->map.size.y = ft_count_line(fd);
}

static void	ft_init(t_data *data)
{
	data->collected = 0;
	data->map.map = NULL;
	data->player.status = IDILE;
	data->player.face_toward = DOWN;
	data->moves = 0;
	data->status = YET;
	data->map.mon_num = 0;
	data->map.to_collect = 0;
}

int32_t	main(int argc, char **argv)
{
	t_data	data;
	int		width;
	int		height;

	if (argc != 2)
		ft_print_error_parameter("Error! Expect only one parameter!\n");
	ft_window_size(&data, argv[1]);
	ft_init(&data);
	read_map(&data, argv[1]);
	width = ((data.map.size.x - 1) * PIXEL) + SPACE;
	height = (data.map.size.y * PIXEL) + SPACE;
	data.mlx = mlx_init(width, height, GAME_TITLE, false);
	rendering(&data);
	if (!data.mlx)
	{
		ft_free_images(&data);
		ft_print_error(&data, "Error! initializing library\n");
	}
	mlx_loop_hook(data.mlx, &animate, &data);
	mlx_key_hook(data.mlx, &detect_keys, &data);
	mlx_loop(data.mlx);
	ft_freemap(data.map.map, data.map.size.y);
	ft_free_images(&data);
	return (EXIT_SUCCESS);
}
