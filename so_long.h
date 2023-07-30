/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 19:31:12 by hchairi           #+#    #+#             */
/*   Updated: 2023/03/20 12:28:41 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <time.h>
# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include "get_next_line.h"
# include "./ft_printf/ft_printf.h"
# define W 64
# define WIDTH_WIN 2560
# define HEIGTH_WIN 1440

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_data
{
	char	**map;
	char	**cpy;
	void	*mlx;
	void	*win;
	void	*floor;
	void	*road;
	void	*player[4];
	void	*coll;
	void	*enemy;
	void	*d1;
	void	*d2;
	char	*s;
	int		i_w;
	int		i_h;
	int		ct_line;
	int		vue;
	int		ct_c;
	int		coin;
	int		move;
	t_pos	*ply;
	t_pos	*p_e;
	t_pos	*en;
	char	*str;
}	t_data;

char	**ft_split(char const *slg, char c);
int		checkmap(t_data *slg, char **tab);
int		checkmap_b(t_data *slg, char **tab);
void	images_to_map(t_data *slg);
int		moves(int keycode, t_data *slg);
void	checkpath(t_data *slg, int i, int j);
void	path(t_data *slg);
void	start(t_data *slg);
void	s_start(t_data *slg);
void	start_b(t_data *slg);
int		c_moves_b(int keycode, t_data *slg);
int		enemy_mv(t_data *slg);
char	*ft_itoa(int n);
int		move_x(t_data *slg, char **tab, t_pos *ply, int i);
int		move_y(t_data *slg, char **tab, t_pos *ply, int i);
int		ft_exit(t_data *slg);
void	ft_exit_err(t_data *slg);

enum e_count {e, p, c, n};

#endif