/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kytan <kytan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 11:13:12 by kytan             #+#    #+#             */
/*   Updated: 2024/06/17 11:13:12 by kytan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

int	find_width(char **split)
{
	int	i;

	if (!split) //gnl failed
		exit_err(LIBFT_ERROR);
	if (!*split)
		exit_err(MAP_EMPTY_ERROR);
	i = 0;
	while (split[i])
		i++;
	free_split(split);
	return (i);
}

int		convert_hex_color(char *color, t_map *map)
{
	while (ft_isdigit(*color) || *color == '-' || *color == '+' || *color == ',')
		color++;
	if (*color && *color == 'x')
	{
		map->iscolor = 1;
		color++;
		return (ft_atoi_base(color, HEX_BASE));
	}
	return (WHITE);
}