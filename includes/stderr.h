/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stderr.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kytan <kytan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 20:13:13 by kytan             #+#    #+#             */
/*   Updated: 2024/06/16 20:13:13 by kytan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#ifndef STDERR_H
# define STDERR_H

# define ERROR_TYPE(x) #x

/** @brief This is the ANSI escape code for yellow
 */
# define COLOR_ERR "\033[33m"
# define RESET_ERR "\033[0m"

#define SUCCESS 0
#define FAILURE 1

#define INVALID_ARGS_ERROR  2
#define FILE_OPEN_ERROR     3
#define MEM_ALLOC_ERROR     4
#define MAP_EMPTY_ERROR     5
#define LIBFT_ERROR         6
#define MLX_ERROR           7
#define ASIAN_FAILURE_ERROR 8



#endif