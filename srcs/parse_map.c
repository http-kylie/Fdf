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
#include "libft.h"

void	parse_map_size(int fd, t_map *map)
{
	char	*line;
	char	**split;

	line = get_next_line(fd);
	split = ft_split(line, ' ');
	map->width = find_width(split);
	while (line)
	{
		map->height++;
		printf("height in loop: %i\n", map->height);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}

void	parse_map_mem(int fd, t_map *map)
{
	int		i;
	int		j;
	char	*line;
	char	**split;

	i = -1;
	alloc_map_mem(map);
	while (++i < map->height)
	{
		line = get_next_line(fd);
		split = ft_split(line, ' ');
		j = -1;
		while (split[++j])
		{
			map->z_2D[i][j] = ft_atoi(split[j]);
			map->colors[i][j] = convert_hex_color(split[j], map);
		}
		free(line);
		free_split(split);
	}
	close(fd);
}