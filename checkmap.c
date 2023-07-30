/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 10:22:51 by hchairi           #+#    #+#             */
/*   Updated: 2023/03/19 11:30:51 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check1(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		if (s[i] != '1')
			return (0);
	return (1);
}

int	check2(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		if (tab[i][0] != '1' || tab[i][ft_strlen(tab[i]) - 1] != '1')
			return (0);
	return (1);
}

int	check_element2(t_data *slg, int i, int j, int *count)
{
	if (slg->map[i][j] == 'P')
	{
		slg->ply->x = j;
		slg->ply->y = i;
		count[p]++;
	}
	else if (slg->map[i][j] == 'E')
	{													
		count[e]++;
		slg->p_e->x = j;
		slg->p_e->y = i;
	}
	else if (slg->map[i][j] == 'C')
		count[c]++;
	else if (slg->map[i][j] != '0' && slg->map[i][j] != '1')
		return (0);
	return (1);
}

int	check_element(t_data *slg, int i, int j)
{
	int	count[3];

	count[e] = 0;
	count[p] = 0;
	count[c] = 0;
	while (slg->map[++i])
	{
		j = -1;
		while (slg->map[i][++j])
			if (!check_element2(slg, i, j, count))
				return (0);
	}
	if (count[c] == 0 || count[e] != 1 || count[p] != 1)
		return (0);
	slg->ct_c = count[c];
	return (1);
}

int	checkmap(t_data *slg, char **tab)
{
	if (((tab && check_element(slg, -1, -1) && check2(tab)
				&& check1(tab[0]) && check1(tab[(slg->ct_line) - 1])))
		&& ((ft_strlen(slg->map[0]) * W <= WIDTH_WIN
				&& slg->ct_line * W <= HEIGTH_WIN)))
		return (1);
	write(1, "Error\ninvalide map", 19);
	ft_exit_err(slg);
	return (0);
}
