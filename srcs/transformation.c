/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kytan <kytan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 19:22:26 by kytan             #+#    #+#             */
/*   Updated: 2024/06/19 19:22:26 by kytan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

/**
 * @brief Applies a series of transformations to a point.
 *
 * This function scales the x, y, and z coordinates of the point by the zoom
 * factor,
 * applies a series of rotations to the point, converts the point to
 * isometric coordinates,
 * and then shifts the point by the shift_x and shift_y values.
 * The z coordinate is scaled by a smaller factor than the x and y coordinates
 * to reduce its impact on the final position of the point.
 *
 * @param fdf A pointer to a t_data structure that contains the display
 * variables and the transformation parameters.
 * @param point The point to which the transformations are applied.
 * @return The transformed point.
 */
t_point	transform_points(t_data *fdf, t_point point)
{
	point.x *= fdf->zoom;
	point.y *= fdf->zoom;
	point.z *= (fdf->zoom / SF) * fdf->ff;
	rot_x(fdf, &point.y, &point.z);
	rot_y(fdf, &point.x, &point.z);
	rot_z(fdf, &point.x, &point.y);
	isometric(fdf, &point.x, &point.y, point.z);
	point.x += fdf->shift_x;
	point.y += fdf->shift_y;
	return (point);
}


/**
 * @brief Creates a new point with the given x and y coordinates and
 * the corresponding z coordinate and color from the map.
 *
 * This function creates a new point with the given x and y coordinates.
 * It sets the z coordinate of the point to the corresponding
 * value from the map's z_ij array. If the map has color data, it sets the
 * color of the point to the corresponding value from the
 * map's colors array. Otherwise, it calculates the color based on the z
 * coordinate.
 *
 * @param x The x coordinate of the new point.
 * @param y The y coordinate of the new point.
 * @param fdf A pointer to a t_data structure that contains the display
 * variables and the map data.
 * @return The new point.
 */
t_point	create_new_point(int x, int y, t_data *fdf)
{
	t_point	point;

	point.x = x;
	point.y = y;
	point.z = fdf->map->z_2D[y][x];
	if (fdf->map->iscolor)
		point.color = fdf->map->colors[y][x];
	else
		point.color = calc_z_color(fdf, point.z);
	return (point);
}