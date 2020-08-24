/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 08:25:54 by clde-ber          #+#    #+#             */
/*   Updated: 2020/08/20 15:20:42 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_struct_bitmap(t_player *player)
{
	player->bitmap.r = 0;
	player->bitmap.g = 0;
	player->bitmap.b = 0;
	player->bitmap.a = 1;
	player->bitmap.resfield = 0;
	player->bitmap.offset = 54;
	player->bitmap.size = 40;
	player->bitmap.plane = 1;
	player->bitmap.depth = 32;
	player->bitmap.compression = 0;
	player->bitmap.zero = 0;
	player->bitmap.len = player->struct_screen.x * player->struct_screen.y * 4;
	player->bitmap.filesize = player->bitmap.len + player->bitmap.offset;
}

void	bmp_write_header(int i, int fd, t_player *player)
{
	player->waste = write(fd, "BM", 2);
		player->waste = write(fd, &player->bitmap.filesize, sizeof(int));
		player->waste = write(fd, &player->bitmap.resfield, sizeof(int));
		player->waste = write(fd, &player->bitmap.offset, sizeof(int));
		player->waste = write(fd, &player->bitmap.size, sizeof(int));
		player->waste = write(fd, &player->struct_screen.x, sizeof(int));
		player->waste = write(fd, &player->struct_screen.y, sizeof(int));
		player->waste = write(fd, &player->bitmap.plane, sizeof(unsigned short));
		player->waste = write(fd, &player->bitmap.depth, sizeof(unsigned short));
		player->waste = write(fd, &player->bitmap.compression, sizeof(int));
		player->waste = write(fd, &player->bitmap.len, sizeof(int));
	while (i < 4)
	{
			player->waste = write(fd, &player->bitmap.zero, sizeof(int));
		i++;
	}
}

void	bmp_write_colors(int i, int j, int fd, t_player *player)
{
	player->bitmap.r = player->ids.img_data[(int)(((i *
	player->struct_screen.x * 4) + (j * 4))) + 2];
	player->bitmap.g = player->ids.img_data[(int)(((i *
	player->struct_screen.x * 4) + (j * 4))) + 1];
	player->bitmap.b = player->ids.img_data[(int)(((i *
	player->struct_screen.x * 4) + (j * 4)))];
	player->bitmap.a = player->ids.img_data[(int)(((i *
	player->struct_screen.x * 4) + (j * 4))) + 3];
		player->waste = write(fd, &player->bitmap.b, sizeof(char));
		player->waste = write(fd, &player->bitmap.g, sizeof(char));
		player->waste = write(fd, &player->bitmap.r, sizeof(char));
		player->waste = write(fd, &player->bitmap.a, sizeof(char));
}

int		create_bmp(t_player *player)
{
	int i;
	int fd;
	int j;

	i = player->struct_screen.y;
	fd = 0;
	j = -1;
	init_struct_bitmap(player);
	if (!(fd = open("image.bmp", O_CREAT, 00700)))
		return (0);
	close(fd);
	if (!(fd = open("image.bmp", O_WRONLY)))
		return (0);
	bmp_write_header(0, fd, player);
	while (--i >= 0)
	{
		while (++j < player->struct_screen.x)
			bmp_write_colors(i, j, fd, player);
		j = -1;
	}
	close(fd);
	return (0);
}

int		main(int argc, char **argv)
{
	char		*title;
	t_player	player;
	char		**map;

	title = "cub3D";
	map = NULL;
	init_map_dim(&player);
	player.save = 0;
	init_map_dim(&player);
	player.bool_start = 0;
	player.start = 1;
	check_file(NULL, 0, 0, &player);
	map = create_map(0, map, player.table_lenght, &player);
	player.map = map;
	if (argc == 2 && argv[1][0] == '-' && argv[1][1] == '-' && argv[1][2]
	== 's' && argv[1][3] == 'a' && argv[1][4] == 'v' && argv[1][5] == 'e')
		player.save = 1;
	player.ids.mlx_ptr = mlx_init();
	if (place_player(-1, -1, 0, &player))
		open_window(-1, -1, &player, title);
	mlx_hook(player.ids.mlx_win, 2, 1L << 0, &key_press, &player);
	mlx_hook(player.ids.mlx_win, 3, 1L << 1, &key_release, &player);
	mlx_hook(player.ids.mlx_win, 17, 1L << 17, &exit_game, &player);
	display_view(0, 0, 0, &player);
	mlx_loop(player.ids.mlx_ptr);
	ft_free2(player.sprite);
	return (0);
}
