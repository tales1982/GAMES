/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlima-de <tlima-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 09:46:13 by tales             #+#    #+#             */
/*   Updated: 2024/06/11 18:21:15 by tlima-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_game_window(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->map_width * TILE_SIZE,
			data->map_height * TILE_SIZE, "So Long");
}
int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		ft_printf("Error\n", argv[0]);
		return (1);
	}
	data.map = load_map(argv[1], &data);
	if (!data.map)
	{
		ft_printf("Error\n");
		return (1);
	}
	data.move_count = 0;
	start_game(&data);
	free_resources(&data);
	return (0);
}
