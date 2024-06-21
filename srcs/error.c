/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kytan <kytan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 22:24:01 by kytan             #+#    #+#             */
/*   Updated: 2024/06/16 22:24:01 by kytan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

void	exit_err(int exit_status)
{
	ft_printf("%s", COLOR_ERR);
	if (exit_status == INVALID_ARGS_ERROR)
		ft_printf("%s: { Usage: ./fdf <map>.fdf }\n", ERROR_TYPE(INVALID_ARGS_ERROR));
	else if (exit_status == FILE_OPEN_ERROR)
		ft_printf("%s: Failed to open file\n", ERROR_TYPE(FILE_OPEN_ERROR));
	else if (exit_status == MEM_ALLOC_ERROR)
		ft_printf("%s: Failed in allocating memory\n", ERROR_TYPE(MEM_ALLOC_ERROR));
	else if (exit_status == MAP_EMPTY_ERROR)
		ft_printf("%s: Map is empty...just like your soul\n", ERROR_TYPE(MAP_EMPTY_ERROR));
	else if (exit_status == LIBFT_ERROR)
		ft_printf("%s: Your libft function failed\n", ERROR_TYPE(LIBFT_ERROR));
	else if (exit_status == MLX_ERROR)
		ft_printf("%s: Your minilibx function failed\n", ERROR_TYPE(MLX_ERROR));
	else if (exit_status == SUCCESS)
		ft_printf("%s: The program ran successfully\n", ERROR_TYPE(SUCCESS));
	else
		ft_printf("%s: You're just a failure in general\n", ERROR_TYPE(ASIAN_FAILURE_ERROR));
	ft_printf("%s", RESET_ERR);
	exit(exit_status);
}
