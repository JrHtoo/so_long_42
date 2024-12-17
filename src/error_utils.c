/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhtoo-h <juhtoo-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:31:09 by juhtoo-h          #+#    #+#             */
/*   Updated: 2024/12/17 17:47:32 by juhtoo-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
