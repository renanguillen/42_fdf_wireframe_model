/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 20:45:39 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/08/09 20:19:59 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WINDOW_HEIGHT 600
# define WINDOW_WIDTH 900
# define MLX_ERROR 1
# define RED_PIXEL 0xFF0000
# define GREEN_PIXEL 0xFF00
# define WHITE_PIXEL 0xFFFFFF

# include <stdlib.h>
# include <X11/X.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include "../libraries/42_libft/libft.h"

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	int		cur_img;
}	t_data;

typedef struct s_dot
{
	int				value;
	char			*color;
}	t_dot;

typedef struct s_matrix
{
	int		row_count;
	int		col_count;
	char	**lines;
	char	**split;
	t_dot	**dot;
}	t_matrix;

int		check_args(int argc, char **argv);
int		count_lines(char *argv);
void	get_lines(int argc, char **argv, t_matrix *matrix);
void	found_error(void **pointer);
void	get_arguments(t_matrix *matrix, int i);
void	write_matrix(t_matrix *matrix);

#endif