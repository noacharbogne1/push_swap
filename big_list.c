/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 10:31:11 by noacharbogn       #+#    #+#             */
/*   Updated: 2024/11/12 10:25:57 by ncharbog         ###   ########.fr       */
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
	if (len_lst(sa) > 3)
	{
		tmp = sa;
		i = find_combination(sa, sb);
		while (i >= 0)
		{
			if (i == combination_rarb(tmp->nb, sa, sb))
				i = 1;
			if (i == combination_rrarrb(tmp->nb, sa, sb))
				i = 1;
			if (i == combination_rrarb(tmp->nb, sa, sb))
				i = 1;
			if (i == combination_rarrb(tmp->nb, sa, sb))
				i = 1;
			else
				tmp = tmp->next;
		}
	}
	else
		three_elems(sa);
}
