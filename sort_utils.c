/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 09:21:34 by ncharbog          #+#    #+#             */
/*   Updated: 2024/11/13 16:37:56 by ncharbog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	positioning_sb(int nb, t_list *sb, int rotation)
{
	t_list	*tmp;
	t_list	*prev;
	t_list	*next;
	int		i;

	i = 0;
	tmp = sb;
	if (rotation == 1)
	{
		tmp = sb->prev;
		while (tmp != sb)
		{
			prev = tmp->prev;
			next = tmp->next;
			if (prev == sb)
				prev = sb->prev;
			if (next == sb)
				next = sb->next;
			if (tmp->nb > nb && prev->nb < nb)
				break;
			if (tmp->nb < nb && prev->nb < nb)
				break;
			i++;
			tmp = tmp->prev;
		}
	}
	else if (rotation == 2)
	{
		while (tmp != sb)
		{
			prev = tmp->prev;
			next = tmp->next;
			if (prev == sb)
				prev = sb->prev;
			if (next == sb)
				next = sb->next;
			if (tmp->nb > nb && next->nb < nb)
				break;
			if (tmp->nb < nb && next->nb < nb)
				break;
			i++;
			tmp = tmp->next;
		}
	}
	return (i);
}
