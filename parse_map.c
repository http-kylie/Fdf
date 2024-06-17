/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kytan <kytan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 18:53:39 by kytan             #+#    #+#             */
/*   Updated: 2024/06/16 18:53:39 by kytan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	parse_map_size(int fd, t_map *map)
{
	char	*line;

	line = get_next_line(fd);
	map->width = find_width(ft_split(line, ' '));
	if (!map->width)
		exit_err(MAP_EMPTY_ERROR);
	while (line)
	{
		map->height++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
}

void	parse_map_mem(int fd, t_map *map)
{
	int		i;
	int		j;
	char	*line;
	char	**split;

	i = -1;
	while (++i < map->height)
	{
		line = get_next_line(fd);
		split = ft_split(line, ' ');
		j = -1;
		while (split[++j])
		{
			map->z_2D[i][j] = ft_atoi(split[j]);
			map->colors[i][j] = convert_hex_color(split[i], map);
		}
		free(line);
		free_split(split);
	}
}