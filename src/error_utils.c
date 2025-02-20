/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhtoo-h <juhtoo-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:31:09 by juhtoo-h          #+#    #+#             */
/*   Updated: 2025/02/13 13:22:43 by juhtoo-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_free_images(t_data *data)
{
	int	i;

	i = 0;
	while (i < 28)
	{
		mlx_delete_image(data->mlx, data->player.walking[i]);
		if (i < 2)
		{
			mlx_delete_image(data->mlx, data->player.idle[i]);
			mlx_delete_image(data->mlx, data->asset[i]);
		}
		if (i < 4)
			mlx_delete_image(data->mlx, data->player.death[i]);
		if (i < 5)
		{
			mlx_delete_image(data->mlx, data->exit.img[i]);
			mlx_delete_image(data->mlx, data->mon[i]);
		}
		if (i < 10)
			mlx_delete_image(data->mlx, data->digit[i]);
		i++;
	}
	mlx_terminate(data->mlx);
}

void	ft_print_error_parameter(char *error_msg)
{
	ft_printf("%s", error_msg);
	exit(EXIT_FAILURE);
}

void	ft_print_error(t_data *data, char *error_msg)
{
	ft_printf("%s", error_msg);
	ft_freemap(data->map.map, data->map.size.y);
	exit(EXIT_FAILURE);
}

void	ft_exit(t_data *data, char *error_msg)
{
	ft_printf("%s", error_msg);
	ft_freemap(data->map.map, data->map.size.y);
	exit(EXIT_FAILURE);
}

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
