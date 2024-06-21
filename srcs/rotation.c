/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kytan <kytan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 02:19:13 by kytan             #+#    #+#             */
/*   Updated: 2024/06/20 02:19:13 by kytan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

/**
 * @brief Rotates a point around the x-axis.
 *
 * This function performs a rotation transformation matrix
 * onto a given point which rotates the point around
 * the x-axis by an angle specified inthe fdf structure.
 * The rotation is done in-place, meaning the original y
 * and z coordinates are modified.
 *
 * The following transformation matrix is applied:
 * | 1  0      0    |
 * | 0  cos(θ) -sin(θ)|
 * | 0  sin(θ)  cos(θ)|
 *
 * @param fdf A pointer to a t_data structure that contains the
 * rotation angle.
 * @param y A pointer to the y coordinate of the point.
 * @param z A pointer to the z coordinate of the point.
 */
void	rot_x(t_data *fdf, int *y, int *z)
{
	float	prev_y;

	prev_y = *y;
	*y = (prev_y * cos(fdf->rot_x)) + (*z * sin(fdf->rot_x));
	*z = (-prev_y * sin(fdf->rot_x)) + (*z * cos(fdf->rot_x));
}

/**
 * @brief Rotates a point around the y-axis.
 *
 * This function rotates a point around the y-axis by an angle
 *  specified in the fdf structure. The rotation is done in-place,
 * meaning the original x and z coordinates are modified.
 *
 * @param fdf A pointer to a t_data structure that contains the
 * rotation angle.
 * @param x A pointer to the x coordinate of the point.
 * @param z A pointer to the z coordinate of the point.
 */
void	rot_y(t_data *fdf, int *x, int *z)
{
	float	prev_x;

	prev_x = *x;
	*x = (*x * cos(fdf->rot_y)) + (*z * sin(fdf->rot_y));
	*z = (-prev_x * sin(fdf->rot_y)) + (*z * cos(fdf->rot_y));
}

/**
 * @brief Rotates a point around the z-axis.
 *
 * This function rotates a point around the z-axis by an angle
 * specified in the fdf structure. The rotation is done in-place,
 * meaning the original x and y coordinates are modified.
 *
 * @param fdf A pointer to a t_data structure that contains the rotation
 * angle.
 * @param x A pointer to the x coordinate of the point.
 * @param y A pointer to the y coordinate of the point.
 */
void	rot_z(t_data *fdf, int *x, int *y)
{
	float	prev_x;

	prev_x = *x;
	*x = (*x * cos(fdf->rot_z)) - (*y * sin(fdf->rot_z));
	*y = (prev_x * sin(fdf->rot_z)) + (*y * cos(fdf->rot_z));
}