/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_operations_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:37:21 by noacharbogn       #+#    #+#             */
/*   Updated: 2024/11/21 10:17:12 by ncharbog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_rarb	calculate_indices_rarb(t_list *sa, t_list *sb, long nb)
{
	t_rarb	rarb;

	rarb.i_sb = positioning_sb(nb, sb);
	if (rarb.i_sb == len_lst(sb))
		rarb.i_sb = 0;
	if (rarb.i_sb != 0)
		rarb.i_sb = len_lst(sb) - rarb.i_sb;
	rarb.i_sa = len_lst(sa) - find_place_sb(sa, nb);
	rarb.same = 0;
	if (rarb.i_sa < rarb.i_sb && rarb.i_sa > 0 && rarb.i_sb > 0)
	{
		rarb.same = rarb.i_sa;
		rarb.i_sb = rarb.i_sb - rarb.same;
		rarb.i_sa = 0;
	}
	else if (rarb.i_sa > rarb.i_sb && rarb.i_sa > 0 && rarb.i_sb > 0)
	{
		rarb.same = rarb.i_sb;
		rarb.i_sa = rarb.i_sa - rarb.same;
		rarb.i_sb = 0;
	}
	return (rarb);
}

t_rrarrb	calculate_indices_rrarrb(t_list *sa, t_list *sb, long nb)
{
	t_rrarrb	rrarrb;

	rrarrb.i_sb = positioning_sb(nb, sb);
	rrarrb.i_sa = find_place_sb(sa, nb);
	rrarrb.same = 0;
	if (rrarrb.i_sa < rrarrb.i_sb && rrarrb.i_sa > 0 && rrarrb.i_sb > 0)
	{
		rrarrb.same = rrarrb.i_sa;
		rrarrb.i_sb = rrarrb.i_sb - rrarrb.same;
		rrarrb.i_sa = 0;
	}
	else if (rrarrb.i_sa > rrarrb.i_sb && rrarrb.i_sa > 0 && rrarrb.i_sb > 0)
	{
		rrarrb.same = rrarrb.i_sb;
		rrarrb.i_sa = rrarrb.i_sa - rrarrb.same;
		rrarrb.i_sb = 0;
	}
	return (rrarrb);
}
