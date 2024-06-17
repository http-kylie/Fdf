/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kytan <kytan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 18:53:58 by kytan             #+#    #+#             */
/*   Updated: 2024/06/16 18:53:58 by kytan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

t_map	*init_map(char *file)
{
	int		fd;
	t_map	*map;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit_perr(file);
	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		exit_err(MEM_ALLOC_ERROR);
	//print_map_mem(map);
	parse_map_size(fd, map);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit_perr(file);
	parse_map_mem(fd, map);
	return (map);
}