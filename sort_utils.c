/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 09:21:34 by ncharbog          #+#    #+#             */
/*   Updated: 2024/11/15 14:38:44 by ncharbog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	positioning_sb(long nb, t_list *sb)
{
	t_list	*tmp;
	t_list	*prev;
	t_list	*next;
	int		i;

	i = 1;
	tmp = sb->next;
	if (nb < min(sb) || nb > max(sb))
		i = find_place(sb, max(sb));
	else
	{
		while (tmp != sb)
		{
			next = tmp->next;
			if (next == sb)
					next = sb->next;
			if (nb > tmp->nb && nb < next->nb)
				break;
			i++;
			tmp = tmp->next;
		}
	}
	return (i);
}

int	find_place(t_list *root, long nb)
{
	t_list	*tmp;
	int		i;

	i = 1;
	tmp = root->next;
	while (tmp->nb != nb)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
