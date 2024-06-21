/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kytan <kytan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 01:00:03 by kytan             #+#    #+#             */
/*   Updated: 2024/06/18 01:00:03 by kytan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
/* FINISH init_mlx*/


void	init_mlx(t_data *fdf)
{
	fdf->mlx = mlx_init();
	if (!fdf->mlx)
	{
		free_map_mem(fdf->map);
		free(fdf);
		exit_err(MLX_ERROR);
	}
	fdf->img->img = mlx_new_image(fdf->mlx, W_WIDTH, W_HEIGHT);
	fdf->win = mlx_new_window(fdf->mlx, W_WIDTH, W_HEIGHT, "kytan 42 FDF ≽^•⩊•^≼");
	if (!fdf->win || !fdf->img)
	{
		close_window(fdf);
		exit_err(MLX_ERROR);
	}
	fdf->img->addr = mlx_get_data_addr(
		fdf->img->img, &fdf->img->bpp, &fdf->img->ln_len, &fdf->img->endian);
	// if (!fdf->img->addr)
	// 	printf("get_data_addr isnt working\n");
}

void	begin_mlx(t_map *map)
{
	t_data	*fdf;

	fdf = init_data(map);
	if (!fdf)
		exit_err(close_window(fdf));
	init_mlx(fdf);
	mlx_hook(fdf->win, 2, (1L<<0), &handle_keypress, fdf);
	mlx_hook(fdf->win, 17, 0, &close_window, fdf);
	draw_map(fdf);
	mlx_loop(fdf->mlx);
}

	//print_data(fdf);