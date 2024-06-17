/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kytan <kytan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 21:27:47 by kytan             #+#    #+#             */
/*   Updated: 2024/06/16 21:27:47 by kytan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_z_2D(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
			printf("%i ", map->z_2D[i][j]);
		printf("\n");
	}
}

void	print_map_mem(t_map *map)
{
	printf("MAP MEMBERS:\n");
	printf("height: %i\n", map->height);
	printf("width: %i\n", map->height);
	printf("z_2D: %p\n", map->z_2D);
	printf("colors: %p\n", map->colors);
	printf("iscolor: %i\n", map->iscolor);
	printf("min_z: %i\n", map->min_z);
	printf("max_z: %i\n\n", map->min_z);
}