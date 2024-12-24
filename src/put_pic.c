/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhtoo-h <juhtoo-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 10:02:43 by juhtoo-h          #+#    #+#             */
/*   Updated: 2024/12/23 12:16:13 by juhtoo-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static mlx_image_t	*t2i(t_data *data
	, char *path, int width, int height)
{
	return (ft_texture_to_image(data, path, width, height));
}

static void	put_character_pic1(t_data *data)
{
	data->player.walking[0] = t2i(data, "textures/s/down1.png", PIXEL, PIXEL);
	data->player.walking[1] = t2i(data, "textures/s/down2.png", PIXEL, PIXEL);
	data->player.walking[2] = t2i(data, "textures/s/down3.png", PIXEL, PIXEL);
	data->player.walking[3] = t2i(data, "textures/s/down4.png", PIXEL, PIXEL);
	data->player.walking[4] = t2i(data, "textures/s/down5.png", PIXEL, PIXEL);
	data->player.walking[5] = t2i(data, "textures/s/down2.png", PIXEL, PIXEL);
	data->player.walking[6] = t2i(data, "textures/s/down5.png", PIXEL, PIXEL);
	data->player.walking[7] = t2i(data, "textures/s/right1.png", PIXEL, PIXEL);
	data->player.walking[8] = t2i(data, "textures/s/right2.png", PIXEL, PIXEL);
	data->player.walking[9] = t2i(data, "textures/s/right3.png", PIXEL, PIXEL);
	data->player.walking[10] = t2i(data, "textures/s/right4.png", PIXEL, PIXEL);
	data->player.walking[11] = t2i(data, "textures/s/right5.png", PIXEL, PIXEL);
	data->player.walking[12] = t2i(data, "textures/s/right2.png", PIXEL, PIXEL);
	data->player.walking[13] = t2i(data, "textures/s/right5.png", PIXEL, PIXEL);
	data->player.walking[14] = t2i(data, "textures/s/left1.png", PIXEL, PIXEL);
	data->player.walking[15] = t2i(data, "textures/s/left2.png", PIXEL, PIXEL);
	data->player.walking[16] = t2i(data, "textures/s/left3.png", PIXEL, PIXEL);
	data->player.walking[17] = t2i(data, "textures/s/left4.png", PIXEL, PIXEL);
	data->player.walking[18] = t2i(data, "textures/s/left5.png", PIXEL, PIXEL);
	data->player.walking[19] = t2i(data, "textures/s/left2.png", PIXEL, PIXEL);
	data->player.walking[20] = t2i(data, "textures/s/left5.png", PIXEL, PIXEL);
	data->player.walking[21] = t2i(data, "textures/s/up1.png", PIXEL, PIXEL);
	data->player.walking[22] = t2i(data, "textures/s/up2.png", PIXEL, PIXEL);
	data->player.walking[23] = t2i(data, "textures/s/up3.png", PIXEL, PIXEL);
	data->player.walking[24] = t2i(data, "textures/s/up4.png", PIXEL, PIXEL);
}

static void	put_character_pic2(t_data *data)
{
	data->player.walking[25] = t2i(data, "textures/s/up5.png", PIXEL, PIXEL);
	data->player.walking[26] = t2i(data, "textures/s/up2.png", PIXEL, PIXEL);
	data->player.walking[27] = t2i(data, "textures/s/up5.png", PIXEL, PIXEL);
	data->player.idle[0] = t2i(data, "textures/s/idle1.png", PIXEL, PIXEL);
	data->player.idle[1] = t2i(data, "textures/s/idle2.png", PIXEL, PIXEL);
	data->player.death[0] = t2i(data, "textures/s/death1.png", PIXEL, PIXEL);
	data->player.death[1] = t2i(data, "textures/s/death1.png", PIXEL, PIXEL);
	data->player.death[2] = t2i(data, "textures/s/death2.png", PIXEL, PIXEL);
	data->player.death[3] = t2i(data, "textures/s/death3.png", PIXEL, PIXEL);
	data->exit.img[0] = t2i(data, "textures/exit/exit1.png", PIXEL, PIXEL);
	data->exit.img[1] = t2i(data, "textures/exit/exit1.png", PIXEL, PIXEL);
	data->exit.img[2] = t2i(data, "textures/exit/exit2.png", PIXEL, PIXEL);
	data->exit.img[3] = t2i(data, "textures/exit/exit3.png", PIXEL, PIXEL);
	data->exit.img[4] = t2i(data, "textures/exit/exit4.png", PIXEL, PIXEL);
	data->digit[0] = t2i(data, "textures/0.png", PIX_D, PIX_D);
	data->digit[1] = t2i(data, "textures/1.png", PIX_D, PIX_D);
	data->digit[2] = t2i(data, "textures/2.png", PIX_D, PIX_D);
	data->digit[3] = t2i(data, "textures/3.png", PIX_D, PIX_D);
	data->digit[4] = t2i(data, "textures/4.png", PIX_D, PIX_D);
	data->digit[5] = t2i(data, "textures/5.png", PIX_D, PIX_D);
	data->digit[6] = t2i(data, "textures/6.png", PIX_D, PIX_D);
	data->digit[7] = t2i(data, "textures/7.png", PIX_D, PIX_D);
	data->digit[8] = t2i(data, "textures/8.png", PIX_D, PIX_D);
	data->digit[9] = t2i(data, "textures/9.png", PIX_D, PIX_D);
}

static void	put_character_pic3(t_data *data)
{
	data->mon[0] = t2i(data, "textures/m/m00.png", PIXEL, PIXEL);
	data->mon[1] = t2i(data, "textures/m/m00.png", PIXEL, PIXEL);
	data->mon[2] = t2i(data, "textures/m/m01.png", PIXEL, PIXEL);
	data->mon[3] = t2i(data, "textures/m/m02.png", PIXEL, PIXEL);
	data->mon[4] = t2i(data, "textures/m/m03.png", PIXEL, PIXEL);
}

void	put_pic(t_data *data)
{
	put_character_pic1(data);
	put_character_pic2(data);
	put_character_pic3(data);
}
