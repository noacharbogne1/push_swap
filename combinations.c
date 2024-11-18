/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combinations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 11:25:47 by noacharbogn       #+#    #+#             */
/*   Updated: 2024/11/18 09:37:46 by ncharbog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_combination(t_list *sa, t_list *sb)
{
	t_list	*tmp;
	int		i;

	tmp = sa->prev;
	i = combination_rarb(tmp->nb, sa, sb);
	while (tmp != sa)
	{
		if (i > combination_rarb(tmp->nb, sa, sb))
			i = combination_rarb(tmp->nb, sa, sb);
		if (i > combination_rrarrb(tmp->nb, sa, sb))
			i = combination_rrarrb(tmp->nb, sa, sb);
		if (i > combination_rrarb(tmp->nb, sa, sb))
			i = combination_rrarb(tmp->nb, sa, sb);
		if (i > combination_rarrb(tmp->nb, sa, sb))
			i = combination_rarrb(tmp->nb, sa, sb);
		tmp = tmp->prev;
	}
	return (i);
}

int	combination_rarb(long nb, t_list *sa, t_list *sb)
{
	int		i;
	int		i_sb;

	i_sb = positioning_sb(nb, sb);
	if (i_sb == len_lst(sb))
		i_sb = 0;
	if (i_sb != 0)
		i_sb = len_lst(sb) - i_sb;
	i = len_lst(sa) - find_place(sa, nb);
	//if (i > 1)
	//	i = i - 1;
	if (i < i_sb)
		i = i + (i_sb - i);
	else if (i > i_sb)
		i = i_sb + (i - i_sb);
	return (i);
}
int	combination_rrarrb(long nb, t_list *sa, t_list *sb)
{
	int		i;
	int		i_sb;

	i_sb = positioning_sb(nb, sb);
	i = find_place(sa, nb);
	if (i < i_sb)
		i = i + (i_sb - i);
	else if (i > i_sb)
		i = i_sb + (i - i_sb);
	return (i);
}

int	combination_rrarb(long nb, t_list *sa, t_list *sb)
{
	int		i;
	int		i_sb;

	i_sb = positioning_sb(nb, sb);
	if (i_sb == len_lst(sb))
		i_sb = 0;
	if (i_sb != 0)
		i_sb = len_lst(sb) - i_sb;
	i = find_place(sa, nb);
	i = i + i_sb;
	return (i);
}
int	combination_rarrb(long nb, t_list *sa, t_list *sb)
{
	int		i;
	int		i_sb;

	i_sb = positioning_sb(nb, sb);
	i = len_lst(sa) - find_place(sa, nb);
	//if (i > 1)
	//	i = i - 1;
	i = i + i_sb;
	return (i);
}
