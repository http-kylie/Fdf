/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kytan <kytan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:15:29 by kytan             #+#    #+#             */
/*   Updated: 2024/06/19 15:15:29 by kytan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

// void	draw(t_data *fdf)
// {
// 	for (int i = W_WIDTH * 0.1; i < W_WIDTH * 0.9; i++) {
// 		for (int j = W_HEIGHT * 0.1; j < W_HEIGHT * 0.9; j++) {
// 			put_pixel_to_img(fdf->img, i, j, WHITE);
// 		}
// 	}
// 	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img->img, 0, 0);
// }


// ZOOM dont understand, where is it calculated? how is the object scaled up/down based on the zoom?
// Research Zoom/Scaling Factor in transformation.c and util.s reset()
void	draw_map(t_data *fdf)
{
	int	x;
	int	y;

	ft_bzero(fdf->img->addr, W_WIDTH * W_HEIGHT * (fdf->img->bpp / 8));
	if (fdf->zoom)
	{
		y = -1;
		while (++y < fdf->map->height)
		{
			x = -1;
			while (++x < fdf->map->width)
			{
				if (x < fdf->map->width - 1)
					bresenham(fdf,
						transform_points(fdf, create_new_point(x, y, fdf)),
						transform_points(fdf, create_new_point(x + 1, y, fdf)));
				if (y < fdf->map->height - 1)
					bresenham(fdf,
						transform_points(fdf, create_new_point(x, y, fdf)),
						transform_points(fdf, create_new_point(x, y + 1, fdf)));
			}
		}
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img->img, 0, 0);
	draw_control_menu(fdf);
}


/**
 * @brief Puts a pixel to the image.
 *
 * This function puts a pixel at the specified (x, y) coordinates in the image.
 * The color of the pixel is specified by the 'color' parameter. The function
 * takes into account the endianness of the system to correctly store the color
 * value.
 *
 * @param fdf Pointer to the t_data structure containing image information.
 * @param x The x-coordinate of the pixel.
 * @param y The y-coordinate of the pixel.
 * @param color The color of the pixel.
 */
void	put_pixel_to_img(t_data *fdf, int x, int y, int color)
{
	int	pixel;

	if (x >= W_WIDTH || y >= W_HEIGHT || x < 0 || y < 0)
		return ;
	pixel = (y * fdf->img->ln_len) + (x * (fdf->img->bpp / 8));
	if (fdf->img->endian == 1)
	{
		fdf->img->addr[pixel + 0] = (color >> AS);
		fdf->img->addr[pixel + 1] = (color >> RS) & BM;
		fdf->img->addr[pixel + 2] = (color >> GS) & BM;
		fdf->img->addr[pixel + 3] = (color) & BM;
	}
	else if (fdf->img->endian == 0)
	{
		fdf->img->addr[pixel + 0] = (color) & BM;
		fdf->img->addr[pixel + 1] = (color >> GS) & BM;
		fdf->img->addr[pixel + 2] = (color >> RS) & BM;
		fdf->img->addr[pixel + 3] = (color >> AS);
	}
}

/**
 * @brief Draws the control information on the window.
 *
 * This function uses the MiniLibX library's mlx_string_put function to draw
 * the control information on the window. The control information includes
 * the keys to press to perform various actions, such as resetting the view,
 * moving the view, zooming in and out, changing the
 * flattening factor, rotating the view, changing the perspective, and closing
 * the application.
 *
 * @param fdf A pointer to a t_display structure that contains the display
 * variables, including the MiniLibX connection and the window.
 */
void	draw_control_menu(t_data *fdf)
{
	void	*mlx;
	void	*win;
	int		vp;

	mlx = fdf->mlx;
	win = fdf->win;
	vp = 20;
	mlx_string_put(mlx, win, 25, vp += 30, WHITE, "CONSTROLS:");
	mlx_string_put(mlx, win, 40, vp += 20, CYAN, "'R' : RESET");
	mlx_string_put(mlx, win, 40, vp += 20, CYAN, "'W' : MOVE UP");
	mlx_string_put(mlx, win, 40, vp += 20, CYAN, "'A' : MOVE DOWN");
	mlx_string_put(mlx, win, 40, vp += 20, CYAN, "'W' : MOVE LEFT");
	mlx_string_put(mlx, win, 40, vp += 20, CYAN, "'W' : MOVE RIGHT");
	mlx_string_put(mlx, win, 40, vp += 20, CYAN, "'+'/'-' : ZOOM IN/OUT");
	mlx_string_put(mlx, win, 40, vp += 20, CYAN, "'UP'/'DOWN' : FLATTEN");
	mlx_string_put(mlx, win, 25, vp += 30, WHITE, "ROTATE VIEW:");
	mlx_string_put(mlx, win, 40, vp += 20, CYAN, "'1'/'2' : X-AXIS");
	mlx_string_put(mlx, win, 40, vp += 20, CYAN, "'3'/'4' : Y-AXIS");
	mlx_string_put(mlx, win, 40, vp += 20, CYAN, "'5'/'6' : Z-AXIS");
	mlx_string_put(mlx, win, 25, vp += 30, WHITE, "TOGGLE PERSPECTIVE:");
	mlx_string_put(mlx, win, 40, vp += 20, CYAN, "'TAB' :  ISOMETRIC/PARALLEL");
	mlx_string_put(mlx, win, 25, vp += 30, WHITE, "EXIT:");
	mlx_string_put(mlx, win, 40, vp += 20, CYAN, "'ESC'/'(X)' : CLOSE WINDOW");
}

// void	put_pixel_to_img(t_img *img, int x, int y, int color)
// {
// 	int				i;
// 	char			*pixel;
// 	unsigned char	*color_ptr;

// 	if (x >= W_WIDTH || y >= W_HEIGHT || x < 0 || y < 0)
// 		return;

// 	pixel = img->addr + (y * img->ln_len + x * (img->bpp / 8));
// 	color_ptr = (unsigned char *)&color;

// 	i = -1;
// 	if (img->endian == 0)
// 		 while (++i < img->bpp / 8)
// 			*pixel++ = *(color_ptr + i);
// 	else
// 		while (++i < img->bpp / 8)
// 			*pixel++ = *(color_ptr + (img->bpp / 8 - 1 - i));
// }