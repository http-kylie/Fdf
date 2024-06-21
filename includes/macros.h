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

/** @def W_WIDTH
 *  @brief This macro defines the width of the window display
 */
# define W_WIDTH 1800
/** @def W_HEIGHT
 * @brief This macro defines the height of the window display
 */
# define W_HEIGHT 1000

/**/
# define HEX_BASE "0123456789ABCDEF"

# define WHITE 0xFFFFFF


/** @def TRANS
 *  @brief This macro defines the size of a single translation adjustment.
 */
# define TRANS	1.5

/** @def ROT
 *  @brief This macro defines the size of a single rotation adjustment.
 */
# define ROT	0.01

/** @def ZOOM
 *  @brief This macro defines the scale factor for a single zoom adjustment.
 */
# define ZOOM	0.1

/** @def FF
 *  @brief This macro defines the flattening factor for a single altitude adjustments.
 */
# define FF		0.01

/** @def SF
 *  @brief This macro defines the scaling factor for the z-coordinate in 3D transformations.
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

/**
 * @brief The number of bits to shift to the right to isolate the red
 * component of a color.
 */
# define RS			16

/**
 * @brief The number of bits to shift to the right to isolate the green
 * component of a color.
 */
# define GS			8

/**
 * @brief The bitmask to apply to isolate the blue component of a color.
 */
# define BM			0xFF

/**
 * @brief The number of bits to shift to isolate the alpha component
 * in a 32-bit color value.
 *
 * This macro represents the number of bits to shift a 32-bit color
 * value to the right to isolate the alpha component.
 * The color value is assumed to be in the format 0xRRGGBBAA, where RR
 * represents the red component, GG the green component,
 * BB the blue component, and AA the alpha component.
 */
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

/**
 * @brief NEON PURPLE
 */
# define N_PURPLE	0xB026FF


# define CYAN 0x00FFFF

#endif