/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_resources.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlima-de <tlima-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 19:43:37 by tales             #+#    #+#             */
/*   Updated: 2024/06/05 18:21:36 by tlima-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_map(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->map_height)
	{
		if (data->map[i])
			free(data->map[i]);
		i++;
	}
	free(data->map);
}

void	free_images(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img_floor);
	mlx_destroy_image(data->mlx, data->img_wall);
	mlx_destroy_image(data->mlx, data->img_collectible);
	mlx_destroy_image(data->mlx, data->img_exit);
}

void	free_player_images(t_data *data)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		mlx_destroy_image(data->mlx, data->img_player_down[i]);
		mlx_destroy_image(data->mlx, data->img_player_left[i]);
		mlx_destroy_image(data->mlx, data->img_player_right[i]);
		mlx_destroy_image(data->mlx, data->img_player_up[i]);
		i++;
	}
}

void	free_mlx_resources(t_data *data)
{
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	free(data->mlx);
}

void	free_resources(t_data *data)
{
	free_map(data);
	free_images(data);
	free_player_images(data);
	free_mlx_resources(data);
}
