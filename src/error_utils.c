/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhtoo-h <juhtoo-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:31:09 by juhtoo-h          #+#    #+#             */
/*   Updated: 2024/10/16 13:25:46 by juhtoo-h         ###   ########.fr       */
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
