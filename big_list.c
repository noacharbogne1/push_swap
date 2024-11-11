/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noacharbogne <noacharbogne@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 10:31:11 by noacharbogn       #+#    #+#             */
/*   Updated: 2024/11/11 11:26:25 by noacharbogn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.c"

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
			if (i == combination_rarb(sa, sb))
				i = exec_rarb(sa, sb);
			if (i == combination_rrarrb(sa, sb))
				i = exec_rrarrb(sa, sb);
			if (i == combination_rrarb(sa, sb))
				i = exec_rrarb(sa, sb);
			if (i == combination_rarrb(sa, sb))
				i = exec_rarrb(sa, sb);
			else
				tmp = tmp->next;
		}
	}
	else
		three_elems(sa);
}
