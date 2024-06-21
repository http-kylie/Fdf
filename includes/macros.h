/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kytan <kytan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 20:13:05 by kytan             #+#    #+#             */
/*   Updated: 2024/06/16 20:13:05 by kytan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#ifndef MACROS_H
# define MACROS_H

# define W_WIDTH 1800
# define W_HEIGHT 1000

# define ERROR_TYPE(x) #x
# define HEX_BASE "0123456789ABCDEF"
# define WHITE 0xFFFFFF


/** @def TRANS
 *  @brief This macro defines the step size for translation movements.
 */
# define TRANS	1.5

/** @def ROT
 *  @brief This macro defines the step size for rotation movements.
 */
# define ROT	0.01

/** @def ZOOM
 *  @brief This macro defines the step size for zoom movements.
 */
# define ZOOM	0.1

/** @def FF
 *  @brief This macro defines the step size for flattening factor adjustments.
 */
# define FF		0.01

/**
 * @brief Scaling factor for the z-coordinate in 3D transformations.
 *
 */
# define SF		10


# define ESC_KEY 65307
# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100

# define R_KEY 114
# define TAB_KEY 65289

# define PS_KEY 61
# define MS_KEY 45

# define UP_KEY 65362
# define LT_KEY 65361
# define RT_KEY 65363
# define DW_KEY 65364

#define KEY_1 49
#define KEY_2 50
#define KEY_3 51
#define KEY_4 52
#define KEY_5 53
#define KEY_6 54

# define RS			16
# define GS			8
# define BM			0xFF
# define AS			24

/**
 * @brief NEON PINK
 */
# define N_PINK		0xFF007F

/**
 * @brief NEON_GREEN
 */
# define N_GREEN	0x39FF14

/**
 * @brief NEON BLUE
 */
# define N_BLUE		0x1B03A3

/**
 * @brief NEON YELLOW
 */
# define N_YELLOW	0xFFFF33

/**
 * @brief NEON ORANGE
 */
# define N_ORANGE	0xFF6600


# define CYAN 0x00FFFF

#endif