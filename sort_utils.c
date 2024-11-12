/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 09:21:34 by ncharbog          #+#    #+#             */
/*   Updated: 2024/11/12 17:43:51 by ncharbog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	positioning_sb(int nb, t_list *sb, int rotation)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = sb->next;
	if (rotation == 1)
	{
		while (tmp != sb)
		{
			if (tmp->nb == min(sb) && nb < tmp->prev->nb)
				break;
			if (tmp->nb > nb && tmp->next->nb < nb)
				break;
			i++;
			tmp = tmp->prev;
		}
	}
	else if (rotation == 2)
	{
		while (tmp != sb)
		{
			if (tmp->prev->nb == min(sb) && nb < tmp->prev->nb)
				break;
			if (tmp->nb > nb && tmp->next->nb < nb)
				break;
			i++;
			tmp = tmp->next;
		}
	}
	return (i);
}

int	min(t_list *root)
{
	t_list	*tmp;
	int		min;

	tmp = root->next;
	min = 2147483647;
	while (tmp != root)
	{
		if (min > tmp->nb)
			min = tmp->nb;
		tmp = tmp->next;
	}
	return (min);
}
