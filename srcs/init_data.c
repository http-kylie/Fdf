/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kytan <kytan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 11:37:40 by kytan             #+#    #+#             */
/*   Updated: 2024/06/18 11:37:40 by kytan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

t_data	*init_data(t_map *map)
{
	t_data	*fdf;

	fdf = ft_calloc(1, sizeof(t_data));
	if (!fdf)
		return (0);
	fdf->img = ft_calloc(1, sizeof(t_img));
	if (!fdf->img)
		return (0);
	fdf->map = map;
	reset_default(fdf);
	//print_data(fdf);
	return (fdf);
}


/**
 * @brief Resets the display variables for a map.
 *
 * This function sets the `zoom`, `shift_x`, `shift_y`, `isometric`,
 * `ff`, `rot_x`, `rot_y`, and `rot_z` fields
 * of the `fdf` structure to their default values.
 *
 * @param fdf A pointer to the t_data structure to reset.
 */
void	reset_default(t_data *fdf)
{
	fdf->zoom = ft_greater((W_WIDTH / fdf->map->width / 2),
			(W_HEIGHT / fdf->map->height / 2));
	fdf->shift_x = W_WIDTH / 2;
	fdf->shift_y = (W_HEIGHT - fdf->map->height * fdf->zoom) / 2;
	fdf->isometric = 1;
	fdf->ff = 1;
	fdf->rot_x = 0;
	fdf->rot_y = 0;
	fdf->rot_z = 0;
}