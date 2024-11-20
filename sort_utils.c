/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 09:21:34 by ncharbog          #+#    #+#             */
/*   Updated: 2024/11/20 10:02:09 by ncharbog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	positioning_sb(long nb, t_list *sb)
{
	t_list	*tmp;
	t_list	*prev;
	int		i;

	i = 1;
	tmp = sb->prev;
	if (nb < min(sb) || nb > max(sb))
		i = find_place_sb(sb, max(sb));
	else
	{
		while (tmp != sb)
		{
			prev = tmp->prev;
			if (prev == sb)
					prev = sb->prev;
			if (nb > tmp->nb && nb < prev->nb)
				break;
			i++;
			tmp = tmp->prev;
		}
	}
	return (i);
}

int	find_place_sb(t_list *root, long nb)
{
	t_list	*tmp;
	int		i;

	i = 1;
	tmp = root->prev;
	while (tmp->nb != nb)
	{
		i++;
		tmp = tmp->prev;
	}
	return (i);
}

int	positioning_sa(long nb, t_list *sa)
{
	t_list	*tmp;
	t_list	*next;
	int		i;

	i = 1;
	tmp = sa->next;
	if (nb < min(sa) || nb > max(sa))
		i = find_place_sa(sa, max(sa));
	else
	{
		while (tmp != sa)
		{
			next = tmp->next;
			if (next == sa)
					next = sa->next;
			if (nb > tmp->nb && nb < next->nb)
				break;
			i++;
			tmp = tmp->next;
		}
	}
	return (i);
}

int	find_place_sa(t_list *root, long nb)
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

void	final_rotate(t_list *sa)
{
	t_list	*tmp;
	int		i;
	int		max;

	i = 0;
	max = -2147483647;
	tmp = sa->next;
	while (tmp != sa)
	{
		if (max < tmp->nb)
		{
			max = tmp->nb;
			i++;
		}
		tmp = tmp->next;
	}
	while (!check_order(sa))
	{
		if (i > len_lst(sa) / 2)
			ep_rra(sa);
		else
			ep_ra(sa);
	}
}
