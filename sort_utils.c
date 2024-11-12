/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 09:21:34 by ncharbog          #+#    #+#             */
/*   Updated: 2024/11/12 10:20:15 by ncharbog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	positioning_sb(int nb, t_list *sb, int rotation)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = sb;
	if (rotation == 1)
	{
		tmp = tmp->prev;
		while (tmp)
		{
			if (tmp->next->nb > nb && tmp->prev->nb < nb)
				break;
			i++;
			tmp = tmp->prev;
		}
	}
	else if (rotation == 2)
	{
		while (tmp)
		{
			if (tmp->next->nb > nb && tmp->prev->nb < nb)
				break;
			i++;
			tmp = tmp->next;
		}
	}
	return (i);
}
