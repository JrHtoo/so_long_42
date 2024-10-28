/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhtoo-h <juhtoo-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 09:08:38 by juhtoo-h          #+#    #+#             */
/*   Updated: 2024/10/23 10:19:42 by juhtoo-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	put_character_pic(t_data *data)
{
	data->player.spin[0]
		= ft_texture_to_image(data, "textures/slime/spin/Spin01.png");
	data->player.spin[1]
		= ft_texture_to_image(data, "textures/slime/spin/Spin02.png");
	data->player.spin[2]
		= ft_texture_to_image(data, "textures/slime/spin/Spin03.png");
	data->player.spin[3]
		= ft_texture_to_image(data, "textures/slime/spin/Spin04.png");
	data->player.spin[4]
		= ft_texture_to_image(data, "textures/slime/spin/Spin05.png");
	data->player.spin[5]
		= ft_texture_to_image(data, "textures/slime/spin/Spin06.png");
	data->player.spin[6]
		= ft_texture_to_image(data, "textures/slime/spin/Spin07.png");
	data->player.spin[7]
		= ft_texture_to_image(data, "textures/slime/spin/Spin08.png");
	data->player.spin[8]
		= ft_texture_to_image(data, "textures/slime/spin/Spin09.png");
	data->player.spin[9]
		= ft_texture_to_image(data, "textures/slime/spin/Spin10.png");
	data->player.spin[10]
		= ft_texture_to_image(data, "textures/slime/spin/Spin11.png");
	data->player.spin[11]
		= ft_texture_to_image(data, "textures/slime/spin/Spin12.png");
}

static void	put_character_pic1(t_data *data)
{
	data->player.idle[0]
		= ft_texture_to_image(data, "textures/character/s_idle1.png");
	data->player.idle[1]
		= ft_texture_to_image(data, "textures/character/s_idle2.png");
	data->player.idle[2]
		= ft_texture_to_image(data, "textures/character/s_idle3.png");
	data->player.idle[3]
		= ft_texture_to_image(data, "textures/character/s_idle4.png");
	data->player.idle[4]
		= ft_texture_to_image(data, "textures/character/s_idle5.png");
	data->player.idle[5]
		= ft_texture_to_image(data, "textures/character/s_idle6.png");
}

static void	animation(void *param)
{
	int	i;
	int	speed;
	static int	frame;
	t_data *data;

	speed = 4;
	data = (t_data *)param;
	i = 0;
	while (i <= 11 * speed)
	{
		if (i == (frame/speed) && i == 0 && frame % speed == 0)
		{
			data->player.spin[0]->instances[0].enabled = true;
			data->player.spin[11]->instances[0].enabled = false;
		}
		else if (i == (frame/speed) && frame % speed == 0)
		{
			data->player.spin[i]->instances[0].enabled = true;
			data->player.spin[(i) - 1]->instances[0].enabled = false;
		}
		i++;
	}
	frame++;
	if (frame == 12 * speed)
			frame = 0;
}

static void	animation1(void *param)
{
	int	i;
	int	speed;
	static int	frame;
	t_data *data;

	speed = 20;
	data = (t_data *)param;
	i = 0;
	while (i <= 5 * speed)
	{
		if (i == frame && i % speed == 0 && i / speed == 0)
		{
			data->player.idle[5]->instances[0].enabled = false;
			data->player.idle[0]->instances[0].enabled = true;
		}
		else if (i == frame && i % speed == 0)
		{
			data->player.idle[(i/speed) - 1]->instances[0].enabled = false;
			data->player.idle[i/speed]->instances[0].enabled = true;
			printf("%d\n",frame);
		}
		i++;
	}
	frame++;
	if (frame == 6 * speed)
			frame = 0;
}

int32_t	main(int argc, char **argv)
{
	t_data	data;
	int		width;
	int		height;

	data.mlx = mlx_init(1000, 1000, "yay", false);
	put_character_pic(&data);
	put_character_pic1(&data);
	int i = 0;
	while (i <= 11)
	{
		mlx_image_to_window(data.mlx, data.player.spin[i], 500, 500);
		data.player.spin[i]->instances[0].enabled = false;
		i++;
	}
	i = 0;
	while (i <= 5)
	{
		mlx_image_to_window(data.mlx, data.player.idle[i], 300, 300);
		data.player.idle[i]->instances[0].enabled = false;
		i++;
	}
	mlx_loop_hook(data.mlx, &animation, &data);
	mlx_loop_hook(data.mlx, &animation1, &data);
	mlx_loop(data.mlx);
	return (EXIT_SUCCESS);
}
