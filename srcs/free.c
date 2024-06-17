/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kytan <kytan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 21:06:35 by kytan             #+#    #+#             */
/*   Updated: 2024/06/16 21:06:35 by kytan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

void	alloc_map_mem(t_map *map)
{
	int	i;

	map->z_2D = ft_calloc(map->height, sizeof(int *));
	map->colors = ft_calloc(map->height, sizeof(int *));
	if (!map->z_2D || !map->colors)
	{
		free_map_mem(map);
		exit_err(MEM_ALLOC_ERROR);
	}
	i = -1;
	while (++i < map->height)
	{
		map->z_2D[i] = ft_calloc(map->width, sizeof(int));
		map->colors[i] = ft_calloc(map->width, sizeof(int));
		if (!map->z_2D[i] || !map->colors[i])
		{
			free_map_mem(map);
			exit_err(MEM_ALLOC_ERROR);
		}
	}
}

void	free_map_mem(t_map *map)
{
	int	i;

	if (!map)
		return ;
	if (map->z_2D)
	{
		i = -1;
		while (++i < map->height && map->z_2D[i])
			free(map->z_2D[i]);
		free(map->z_2D);
	}
	if (map->colors)
	{
		i = -1;
		while (++i < map->height && map->colors[i])
			free(map->colors[i]);
		free(map->colors);
	}
	free(map);
}

void	free_split(char **split)
{
	int	j;

	j = 0;
	while (split[j])
		free(split[j++]);
	free(split);
}