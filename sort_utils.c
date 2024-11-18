/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 09:21:34 by ncharbog          #+#    #+#             */
/*   Updated: 2024/11/18 11:14:45 by ncharbog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	positioning_sb(long nb, t_list *sb)
{
	t_list	*tmp;
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

int	case_r(long nb, t_list *sa)
{
	int		i;

	i = positioning_sb(nb, sa);
	if (i == len_lst(sa))
		i = 0;
	if (i != 0)
		i = len_lst(sa) - i;
	return (i);
}

int	case_rr(long nb, t_list *sa)
{
	int		i;

	i = positioning_sb(nb, sa);
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
			break;
		}
		tmp = tmp->next;
		i++;
	}
	while (!check_order(sa))
	{
		if (i > len_lst(sa) / 2)
			rotate(sa);
		else
			reverse_rotate(sa);
	}
}
