/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhtoo-h <juhtoo-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:05:10 by juhtoo-h          #+#    #+#             */
/*   Updated: 2024/10/23 10:13:44 by juhtoo-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	ft_window_size(t_data *data, char *map_path)
{
	int	fd;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
	{
		perror("Error\nInvalid map_path/map\n");
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
}

int32_t	main(int argc, char **argv)
{
	t_data	data;
	int		width;
	int		height;

	if (argc != 2)
		ft_print_error(&data, "Error! Expect only one parameter!");
	ft_window_size(&data, argv[1]);
	ft_init(&data);
	read_map(&data, argv[1]);
	width = ((data.map.size.x - 1) * PIXEL) + SPACE;
	height = (data.map.size.y * PIXEL) + SPACE;
	data.mlx = mlx_init(width, height, GAME_TITLE, false);
	rendering(&data);
	if (!data.mlx)
		ft_print_error(&data, "Error initializing library\n");
	mlx_loop_hook(data.mlx, &animate, &data);
	mlx_key_hook(data.mlx, &detect_keys, &data);
	mlx_loop(data.mlx);
	ft_freemap(data.map.map, data.map.size.y);
	return (EXIT_SUCCESS);
}
