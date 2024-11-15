/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 10:31:11 by noacharbogn       #+#    #+#             */
/*   Updated: 2024/11/15 16:52:18 by ncharbog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_list(t_list *sa, t_list *sb)
{
	t_list	*tmp;
	int		i;

	i = 0;
	push(sa, sb);
	push(sa, sb);
	if (!check_order(sb))
		swap(sb);
	while (len_lst(sa) > 3)
	{
		tmp = sa->prev;
		i = find_combination(sa, sb);
		while (i >= 0)
		{
			if (i == combination_rarb(tmp->nb, sa, sb))
				i = exec_rarb(sa, sb, tmp->nb);
			else if (i == combination_rrarrb(tmp->nb, sa, sb))
				i = exec_rrarrb(sa, sb, tmp->nb);
			else if (i == combination_rrarb(tmp->nb, sa, sb))
				i = exec_rrarb(sa, sb, tmp->nb);
			else if (i == combination_rarrb(tmp->nb, sa, sb))
				i = exec_rarrb(sa, sb, tmp->nb);
			else
				tmp = tmp->prev;
		}
	}
	if (len_lst(sa) == 3)
		three_elems(sa);
}

void	place_in_a(t_list *sa, t_list *sb)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = sb->prev;
	while (tmp != sb)
	{
		if (tmp > sa->prev)
		{
			push(sb, sa);
			tmp = sb->prev
		}
		else
		{
			i = find_case(tmp->nb, sa);
			if (i == case_r(tmp->nb, sa))
				exec_case_r(tmp->nb, sa);
			if (i == case_rr(tmp->nb, sa))
				exec_case_r(tmp->nb, sa);
		}
		tmp = sb->prev;
	}
}

int	find_case(long nb, t_list *root)
{
	int	i;

	i = case_r(nb, root);
	if (i > case_rr(nb, root))
		i = case_rr(nb, root);
	return (i);
}