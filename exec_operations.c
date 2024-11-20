/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noacharbogne <noacharbogne@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:52:05 by ncharbog          #+#    #+#             */
/*   Updated: 2024/11/20 18:05:12 by noacharbogn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	exec_rarb(t_list *sa, t_list *sb, long nb)
{
	t_rarb	rarb;

	rarb = calculate_indices_rarb(sa, sb, nb);
	while (rarb.same > 0)
	{
		ep_rr(sa, sb);
		rarb.same--;
	}
	while (rarb.i_sb > 0)
	{
		ep_rb(sb);
		rarb.i_sb--;
	}
	while (rarb.i_sa > 0)
	{
		ep_ra(sa);
		rarb.i_sa--;
	}
	ep_pb(sa, sb);
	return (-1);
}

int	exec_rrarrb(t_list *sa, t_list *sb, long nb)
{
	t_rrarrb	rrarrb;
	
	rrarrb = calculate_indices_rrarrb(sa, sb, nb);
	while (rrarrb.same)
	{
		ep_rrr(sa, sb);
		rrarrb.same--;
	}
	while (rrarrb.i_sb > 0)
	{
		ep_rrb(sb);
		rrarrb.i_sb--;
	}
	while (rrarrb.i_sa > 0)
	{
		ep_rra(sa);
		rrarrb.i_sa--;
	}
	ep_pb(sa, sb);
	return (-1);
}

int	exec_rrarb(t_list *sa, t_list *sb, long nb)
{
	int	i_sb;
	int	i_sa;

	i_sb = positioning_sb(nb, sb);
	if (i_sb == len_lst(sb))
		i_sb = 0;
	if (i_sb != 0)
		i_sb = len_lst(sb) - i_sb;
	i_sa = find_place_sb(sa, nb);
	while (i_sb > 0)
	{
		ep_rb(sb);
		i_sb--;
	}
	while (i_sa > 0)
	{
		ep_rra(sa);
		i_sa--;
	}
	ep_pb(sa, sb);
	return (-1);
}

int	exec_rarrb(t_list *sa, t_list *sb, long nb)
{
	int	i_sb;
	int	i_sa;

	i_sb = positioning_sb(nb, sb);
	i_sa = len_lst(sa) - find_place_sb(sa, nb);
	while (i_sb > 0)
	{
		ep_rrb(sb);
		i_sb--;
	}
	while (i_sa > 0)
	{
		ep_ra(sa);
		i_sa--;
	}
	ep_pb(sa, sb);
	return (-1);
}
