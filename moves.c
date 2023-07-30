/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 14:28:59 by hchairi           #+#    #+#             */
/*   Updated: 2023/03/19 11:33:28 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	suite_mv_y(t_data *slg, char **tab, t_pos *ply, int i)
{
	if (tab[ply->y + i][ply->x] == 'C')
		slg->coin++;
	tab[ply->y][ply->x] = '0';
	if (ply->y == slg->p_e->y && ply->x == slg->p_e->x)
		tab[ply->y][ply->x] = 'E';
	ply->y = ply->y + i;
	tab[ply->y][ply->x] = 'P';
	slg->move++;
}

void	suite_mv_x(t_data *slg, char **tab, t_pos *ply, int i)
{
	if (tab[ply->y][ply->x + i] == 'C')
		slg->coin++;
	tab[ply->y][ply->x] = '0';
	if (ply->y == slg->p_e->y && ply->x == slg->p_e->x)
		tab[ply->y][ply->x] = 'E';
	ply->x = ply->x + i;
	tab[ply->y][ply->x] = 'P';
	slg->move++;
}

int	move_y(t_data *slg, char **tab, t_pos *ply, int i)
{
	int	t;

	t = 1;
	if (tab[ply->y + i][ply->x] == '1')
		t = 0;
	if ((tab[ply->y + i][ply->x] == 'E' && slg->ct_c == slg->coin)
		|| tab[ply->y + i][ply->x] == 'N')
	{
		slg->move++;
		ft_exit(slg);
	}
	else if (tab[ply->y + i][ply->x] != '1' && (1 ||
		(ply->y == slg->p_e->y && ply->x == slg->p_e->x
		&& slg->ct_c != slg->coin)))
		suite_mv_y(slg, tab, ply, i);
	if (i > 0)
		slg->vue = 0;
	else
		slg->vue = 3;
	return (t);
}

int	move_x(t_data *slg, char **tab, t_pos *ply, int i)
{
	int	t;

	t = 1;
	if (tab[ply->y][ply->x + i] == '1')
		t = 0;
	if ((tab[ply->y][ply->x + i] == 'E' && slg->ct_c == slg->coin)
		|| tab[ply->y][ply->x + i] == 'N')
	{
		slg->move++;
		ft_exit(slg);
	}
	else if (tab[ply->y][ply->x + i] != '1' && (1 ||
		(ply->y == slg->p_e->y && ply->x == slg->p_e->x
		&& slg->ct_c != slg->coin)))
		suite_mv_x(slg, tab, ply, i);
	if (i > 0)
		slg->vue = 1;
	else
		slg->vue = 2;
	return (t);
}

int	moves(int keycode, t_data *slg)
{
	static int	mv;

	mv = slg->move;
	if (keycode == 126)
		move_y(slg, slg->map, slg->ply, -1);
	else if (keycode == 125)
		move_y(slg, slg->map, slg->ply, 1);
	else if (keycode == 124)
		move_x(slg, slg->map, slg->ply, 1);
	else if (keycode == 123)
		move_x(slg, slg->map, slg->ply, -1);
	else if (keycode == 53)
		ft_exit(slg);
	if (mv != slg->move)
		ft_printf("move %d\n ", slg->move);
	images_to_map(slg);
	return (0);
}
