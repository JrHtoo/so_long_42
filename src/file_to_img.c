/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhtoo-h <juhtoo-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:21:49 by juhtoo-h          #+#    #+#             */
/*   Updated: 2024/10/23 15:21:21 by juhtoo-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

mlx_image_t	*ft_texture_to_image(t_data *data, char *path,
	int width, int height)
{
	mlx_image_t		*img;
	mlx_texture_t	*texture;

	texture = mlx_load_png(path);
	if (!texture)
		ft_print_error(data, "Texture is not texturing\n");
	img = mlx_texture_to_image(data->mlx, texture);
	if (!img)
		ft_print_error(data, "Image is not imaging\n");
	mlx_resize_image(img, width, height);
	mlx_delete_texture(texture);
	return (img);
}

static void	fill_background(t_data *data)
{
	mlx_image_t		*img;
	int				x;
	int				y;

	img = ft_texture_to_image(data, IMG_BACKGROUND, PIXEL, PIXEL);
	y = 1;
	while (y <= data->map.size.y)
	{
		x = 1;
		while (x < data->map.size.x)
		{
			mlx_image_to_window(data->mlx, img, PIXEL * x, PIXEL * y);
			x++;
		}
		y++;
	}
}

static void	fill_wall(t_data *data)
{
	mlx_image_t	*i[4];
	t_pos		p;

	i[0] = ft_texture_to_image(data, "textures/wall.png", PIXEL, PIXEL);
	i[1] = ft_texture_to_image(data, "textures/wall.png", PIXEL, PIXEL);
	i[2] = ft_texture_to_image(data, "textures/wall_side.png", PIXEL, PIXEL);
	i[3] = ft_texture_to_image(data, "textures/wall_side.png", PIXEL, PIXEL);
	p.y = 1;
	while (p.y <= data->map.size.y)
	{
		p.x = 1;
		while (p.x < data->map.size.x)
		{
			if (p.y == 1)
				mlx_image_to_window(data->mlx, i[0], PIXEL * p.x, PIXEL * p.y);
			else if (p.y == data->map.size.y)
				mlx_image_to_window(data->mlx, i[1], PIXEL * p.x, PIXEL * p.y);
			else if (p.x == 1)
				mlx_image_to_window(data->mlx, i[2], PIXEL * p.x, PIXEL * p.y);
			else if (p.x == data->map.size.x - 1)
				mlx_image_to_window(data->mlx, i[3], PIXEL * p.x, PIXEL * p.y);
			p.x++;
		}
		p.y++;
	}
}

static void	fill_everything(t_data data)
{
	int			x;
	int			y;
	mlx_image_t	*coin;
	mlx_image_t	*wall;

	coin = ft_texture_to_image(&data, "textures/Icon20.png", PIXEL, PIXEL);
	wall = ft_texture_to_image(&data, "textures/wall1.png", PIXEL, PIXEL);
	y = 1;
	while (y < data.map.size.y)
	{
		x = 1;
		while (x < data.map.size.x - 2)
		{
			if (data.map.map[y][x] == PLAYER)
				mlx_image_to_window(data.mlx,
					data.player.idle[0], PIXEL * (x + 1), PIXEL * (y + 1));
			else if (data.map.map[y][x] == COIN)
				mlx_image_to_window(data.mlx,
					coin, PIXEL * (x + 1), PIXEL * (y + 1));
			else if (data.map.map[y][x] == WALL)
				mlx_image_to_window(data.mlx,
					wall, PIXEL * (x + 1), PIXEL * (y + 1));
			x++;
		}
		y++;
	}
}

static void	render_sprite(t_data data)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		mlx_image_to_window(data.mlx, data.player.walking[i],
			PIXEL * (data.player.position.x + 1),
			PIXEL * (data.player.position.y + 1));
		data.player.walking[i]->instances->enabled = false;
		i++;
	}
	mlx_image_to_window(data.mlx, data.player.idle[1],
		PIXEL * (data.player.position.x + 1),
		PIXEL * (data.player.position.y + 1));
	data.player.idle[1]->instances->enabled = false;
}

void	rendering(t_data *data)
{
	fill_background(data);
	fill_wall(data);
	put_pic(data);
	fill_everything(*data);
	render_sprite(*data);
}
