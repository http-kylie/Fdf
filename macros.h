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

# define ERROR_TYPE(x) #x
# define DEBUG_PRINT(x) printf("DEBUG: &%s is %p\n", #x, (void *)&x)
# define HEX_BASE "0123456789abcdef"

#endif