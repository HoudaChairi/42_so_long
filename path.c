/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 14:29:57 by hchairi           #+#    #+#             */
/*   Updated: 2023/03/20 11:31:34 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	path(t_data *slg)
{
	int	i;
	int	j;

	i = 0;
	while (slg->cpy[i])
	{
		j = 0;
		while (slg->cpy[i][j])
		{
			if (slg->cpy[i][j] == 'P' || slg->cpy[i][j] == 'E'
				|| slg->cpy[i][j] == 'C')
			{
				write(1, "Error\ninvalide path", 19);
				ft_exit_err(slg);
			}
			j++;
		}
		i++;
	}
}

void	checkpath(t_data *slg, int i, int j)
{
	int	xl;
	int	yl;

	xl = ft_strlen(slg->map[0]);
	yl = slg->ct_line;
	if (i > yl || i < 0 || j > xl || j < 0 || slg->cpy[i][j] == '1')
		return ;
	slg->cpy[i][j] = '1';
	checkpath(slg, i + 1, j);
	checkpath(slg, i - 1, j);
	checkpath(slg, i, j + 1);
	checkpath(slg, i, j - 1);
}
