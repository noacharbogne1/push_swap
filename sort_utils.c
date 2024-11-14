/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 09:21:34 by ncharbog          #+#    #+#             */
/*   Updated: 2024/11/14 10:31:40 by ncharbog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	positioning_sb(int nb, int rotation, t_list *sb)
{
	t_list	*tmp;
	t_list	*next;
	int		i;

	i = 1;
	tmp = sb->next;
	//if (nb > tmp->nb && nb < sb->prev->nb)
		//i = 0;
	if (nb < min(sb))
		i = find_place(sb, min(sb), rotation);
	else if (nb > max(sb))
		i = find_place(sb, max(sb), rotation);
	else
	{
		while (tmp != sb)
		{
			next = tmp->next;
			if (next == sb)
				next = sb->next;
			if (tmp->nb > nb && next->nb < nb)
				break;
			i++;
			tmp = tmp->next;
		}
	}
	return (i);
}

int	find_place(t_list *root, int nb, int rotation)
{
	t_list	*tmp;
	int		i;

	tmp = root;
	i = 0;
	if (rotation == 1)
	{
		tmp = root->prev;
		while (tmp->nb != nb)
		{
			i++;
			tmp = tmp->prev;
		}
	}
	if (rotation == 2)
	{
		while (tmp->nb != nb)
		{
			i++;
			tmp = tmp->next;
		}
	}
	return (i);
}