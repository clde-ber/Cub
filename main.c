/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 08:25:54 by clde-ber          #+#    #+#             */
/*   Updated: 2020/08/28 09:36:15 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	exit_program(t_player *player)
{
	if (player->xpm_path_no)
		free(player->xpm_path_no);
	if (player->xpm_path_so)
		free(player->xpm_path_so);
	if (player->xpm_path_we)
		free(player->xpm_path_we);
	if (player->xpm_path_ea)
		free(player->xpm_path_ea);
	if (player->xpm_path_sp)
		free(player->xpm_path_sp);
	init_struct_ids(player);
	init_struct_player_exit(player);
	init_struct_screen_exit(player);
	init_struct_side_s_e(player);
	init_struct_bitmap_exit(player);
	exit(0);
}

void	hooks(t_player *player)
{
	mlx_hook(player->ids.mlx_win, 2, 1L << 0, &key_press, player);
	mlx_hook(player->ids.mlx_win, 3, 1L << 1, &key_release, player);
	mlx_hook(player->ids.mlx_win, 17, 1L << 17, &exit_game, player);
}

void	player_placement(t_player *player, char *title)
{
	if (place_player(-1, -1, 0, player) != -1)
		open_window(-1, -1, player, title);
	else
		exit_program(player);
}

int		main(int argc, char **argv)
{
	char		*title;
	t_player	player;
	char		**map;

	title = "cub3D";
	map = NULL;
	init_map_dim(&player);
	init_struct_player(&player);
	init_struct_screen(&player);
	init_struct_ids(&player);
	init_struct_side_s_e(&player);
	check_file(NULL, 0, 0, &player);
	map = create_map(0, map, player.table_lenght, &player);
	player.map = map;
	if (argc == 2 && argv[1][0] == '-' && argv[1][1] == '-' && argv[1][2]
	== 's' && argv[1][3] == 'a' && argv[1][4] == 'v' && argv[1][5] == 'e')
		player.save = 1;
	player.ids.mlx_ptr = mlx_init();
	player_placement(&player, title);
	hooks(&player);
	display_view(0, 0, 0, &player);
	mlx_loop(player.ids.mlx_ptr);
	init_struct_ids(&player);
	return (0);
}
