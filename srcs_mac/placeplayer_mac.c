/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placeplayer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 10:34:22 by clde-ber          #+#    #+#             */
/*   Updated: 2020/09/04 16:52:52 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_mac.h"

int		player_placement_error(int i, int j, t_player *player)
{
	if (i == 0 || i == player->table_lenght - 1 || j == 0 ||
	j == (int)ft_strlen(player->map[i]) - 1)
	{
		player->waste = write(1, "Error\nPlayer.\n", 14);
		if (player->map)
			ft_free_tab(player->map);
		exit_program(player, 0);
		return (-1);
	}
	return (1);
}

void	player_coord(int *count, t_player *player, int i, int j)
{
	*count += 1;
	player->map[i][j] = '0';
	player->x = (i + 1) * CELL_SIZE + CELL_SIZE / 2;
	player->y = (j + 1) * CELL_SIZE + CELL_SIZE / 2;
}

int		is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	else
		return (0);
}

int		place_player(int i, int j, int count, t_player *player)
{
	while (++i < player->table_lenght)
	{
		while (player->map[i][++j])
		{
			if (is_player(player->map[i][j]))
			{
				if (player_placement_error(i, j, player) == -1)
					return (0);
				if (i != 0 && i != player->table_lenght - 1 && j != 0 &&
				j != (int)ft_strlen(player->map[i]) - 1)
				{
					if (player->map[i][j] == 'W' || player->map[i][j] == 'E')
						player->teta = (player->map[i][j] == 'W') ?
						-VIEW_ANGLE : VIEW_ANGLE;
					if (player->map[i][j] == 'N' || player->map[i][j] == 'S')
						player->teta = (player->map[i][j] == 'N') ? 0 :
						VIEW_ANGLE * 2;
					player_coord(&count, player, i, j);
				}
			}
		}
		j = -1;
	}
	player->waste = (count != 1) ? write(1, "Error\nPlayer.\n", 14) : 0;
	return (count == 1) ? 1 : -1;
}
