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

void	exit_err(int exit_status)
{
	if (exit_status == INVALID_ARGS_ERROR)
		printf("%s: { Usage: ./fdf <map>.fdf }\n", ERROR_TYPE(INVALID_ARGS_ERROR));
	else if (exit_status == FILE_OPEN_ERROR)
		printf("%s: Failed to open file\n", ERROR_TYPE(FILE_OPEN_ERROR));
	else if (exit_status == MEM_ALLOC_ERROR)
		printf("%s: Failed in allocating memory\n", ERROR_TYPE(MEM_ALLOC_ERROR));
	else if (exit_status == MAP_EMPTY_ERROR)
		printf("%s: Map is empty...just like your soul\n", ERROR_TYPE(MAP_EMPTY_ERROR));
	else if (exit_status == LIBFT_ERROR)
		printf("%s: Your libft function failed\n", ERROR_TYPE(LIBFT_ERROR));
	else
		printf("%s: You're just a failure in general\n", ERROR_TYPE(ASIAN_FAILURE_ERROR));
	exit(exit_status);
}

void	exit_perr(const char *error_message)
{
	perror(error_message);
	exit(FAILURE);
}