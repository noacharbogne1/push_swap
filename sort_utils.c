/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 09:21:34 by ncharbog          #+#    #+#             */
/*   Updated: 2024/11/14 17:52:40 by ncharbog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	positioning_sb(int nb, t_list *sb)
{
	t_list	*tmp;
	t_list	*prev;
	t_list	*next;
	int		i;

	i = 1;
	tmp = sb->next;
	if (nb < min(sb) || nb > max(sb))
		i = find_place(sb, max(sb)) - 1;
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

int	find_place(t_list *root, int nb)
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
