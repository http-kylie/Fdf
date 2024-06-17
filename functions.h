/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kytan <kytan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 20:12:56 by kytan             #+#    #+#             */
/*   Updated: 2024/06/16 20:12:56 by kytan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

/*=============================== PARSING ====================================*/

t_map	*init_map(char *file);
void	parse_map_size(int fd, t_map *map);
void	parse_map_mem(int fd, t_map *map);

int		find_width(char **split);
int		convert_hex_color(char *color, t_map *map);


/*================================ FREE ======================================*/

void	alloc_map_mem(t_map *map);
void	free_map_mem(t_map *map);
void	free_split(char **split);


/*================================ ERROR =====================================*/

void	exit_err(int exit_status);
void	exit_perr(const char *error_message);


/*================================ TEMP ======================================*/

void	print_z_2D(t_map *map);
void	print_map_mem(t_map *map);


#endif